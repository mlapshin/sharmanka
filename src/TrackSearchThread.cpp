#include "shr/Prerequisites.hpp"
#include "shr/TrackSearchThread.hpp"
#include "wx/protocol/http.h"
#include "wx/strconv.h"
#include "shr/Application.hpp"
#include "wx/regex.h"
#include "wx/tokenzr.h"
#include "shr/StringUtil.hpp"


#define BUFFER_SIZE 10000

namespace shr
{

TrackSearchThread::TrackSearchThread(wxEvtHandler* eventHandler, const wxString& q, int offset)
    : wxThread(wxTHREAD_JOINABLE), m_query(q), m_offset(offset)
{
  m_eventReceiver = eventHandler;
  m_totalTracks = 0;
  Create();
}

wxString TrackSearchThread::GetPage(const wxString& path)
{
  wxString result;
  wxHTTP http;
  http.SetFlags(wxSOCKET_BLOCK);
  http.SetHeader(_T("Content-Type"), _T("text/html; charset=windows-1251"));
  http.SetHeader(_T("User-Agent"), SHARMANKA_USER_AGENT);
  http.SetHeader(_T("Cookie"), _T("remixlang=0; remixchk=5; remixsid=" + wxGetApp().GetSid()));
  http.SetTimeout(10);

  http.Connect(_T("vkontakte.ru"));

  if(!TestDestroy()) {
    wxInputStream* httpStream = http.GetInputStream(path);

    if (http.GetError() == wxPROTO_NOERR && http.GetResponse() == 200 && httpStream) {
      char buf[BUFFER_SIZE];
      size_t bytesRead = 0;

      do {
        bytesRead = httpStream->Read(buf, BUFFER_SIZE).LastRead();
        result += wxString((const char*)buf, wxCSConv(wxT("windows-1251")), bytesRead);
        Pulse();
      } while (!TestDestroy() && bytesRead > 0);
    } else {
      // Nothing to do here?
    }
  }

  return result;
}

Track TrackSearchThread::GetTrackFromAudioRow(const wxString& ar)
{
  static wxRegEx op(_T("operate\\(([^)]+)\\)"));
  static wxRegEx titles(_T("<b id=\"performer\\d+\">([^<]+)</b> - <span id=\"title\\d+\">(<a href=[^>]+>)?([^<]+)</(span|a)>"), wxRE_ADVANCED);
  static wxRegEx drtn(_T("<div class=\"duration\">(\\d+):(\\d+)</div>"), wxRE_ADVANCED);

  size_t start;
  size_t len;

  wxArrayString opArgs;
  wxString artist;
  wxString title;
  int duration = 0;

  if (op.Matches(ar)) {
    op.GetMatch(&start, &len, 1);

    opArgs = wxStringTokenize(ar.Mid(start, len), _T(","));
    opArgs[3].Replace(_T("'"), _T(""));
  }

  if (titles.Matches(ar)) {
    titles.GetMatch(&start, &len, 1);
    artist = ar.Mid(start, len).Trim();

    titles.GetMatch(&start, &len, 3);
    title = ar.Mid(start, len).Trim();
  } else {
    std::cout << ar.mb_str() << std::endl;
  }

  if (drtn.Matches(ar)) {
    drtn.GetMatch(&start, &len, 1);
    long minutes;
    ar.Mid(start, len).ToLong(&minutes);

    drtn.GetMatch(&start, &len, 2);
    long seconds;
    ar.Mid(start, len).ToLong(&seconds);

    duration = minutes * 60 + seconds;
  }

  return Track(artist, title, duration, opArgs[1], opArgs[2], opArgs[3]);
}

void* TrackSearchThread::Entry()
{
  wxString encodedQuery = URLEncode(wxString::From8BitData(m_query.mb_str(wxCSConv(wxT("windows-1251")))));
  wxString page = GetPage(_T("/gsearch.php?section=audio&q=") + encodedQuery + _T("&offset=") + wxString::Format(_T("%d"), m_offset));
  static wxRegEx totalTracksRe(_T("<div id=\"audio\" class=\"sec_row\"><div class=\"sec_pad_sel\"><span>\\D+ \\((\\d+)\\)"), wxRE_ADVANCED);

  size_t i = 0;
  size_t j = 0;

  while (!TestDestroy() && (i = page.find(_T("<div class=\"audioRow"), j)) != wxString::npos) {
    j = page.find(_T("</table>"), i);

    if (j != wxString::npos) {
      wxString audioRow = page.Mid(i, j - i);
      m_tracks.push_back(GetTrackFromAudioRow(audioRow));
      Pulse(m_tracks.size());
    }
  }

  if (totalTracksRe.Matches(page)) {
    size_t a = 0;
    size_t b = 0;
    totalTracksRe.GetMatch(&a, &b, 1);
    page.Mid(a, b).ToLong(&m_totalTracks);
  }

  std::cout << m_tracks.size() << " / " << m_totalTracks << " tracks found" << std::endl;

  if(m_tracks.size() == 0) {
    std::cout << page.mb_str() << std::endl;
  }

  if(page.Length() > 0) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TSE_COMPLETED );
    wxPostEvent( m_eventReceiver, event );
  } else {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TSE_ERROR );
    wxPostEvent( m_eventReceiver, event );
  }

  return NULL;
}

void TrackSearchThread::Pulse(int prgrs)
{
  wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TSE_PULSE );
  event.SetInt(prgrs);
  wxPostEvent( m_eventReceiver, event );
}

}
