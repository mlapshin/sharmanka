#include "shr/Prerequisites.hpp"
#include "shr/TrackSearchThread.hpp"
#include "wx/protocol/http.h"
#include "wx/strconv.h"
#include "shr/Application.hpp"

#define BUFFER_SIZE 10000

namespace shr
{

TrackSearchThread::TrackSearchThread(wxEvtHandler* eventHandler)
    : wxThread(wxTHREAD_JOINABLE)
{
  m_eventReceiver = eventHandler;
  Create();
}

void* TrackSearchThread::Entry()
{
  wxString result;
  wxHTTP http;
  http.SetFlags(wxSOCKET_BLOCK);
  http.SetHeader(_T("User-Agent"), SHARMANKA_USER_AGENT);
  http.SetHeader(_T("Cookie"), _T("remixlang=0; remixchk=5; remixsid=" + wxGetApp().GetSid()));
  http.SetTimeout(10);

  http.Connect(_T("vkontakte.ru"));
  wxInputStream* httpStream = http.GetInputStream(_T("/id145958"));

  if (http.GetError() == wxPROTO_NOERR && httpStream) {
    char buf[BUFFER_SIZE];
    size_t bytesRead = 0;

    do {
      bytesRead = httpStream->Read(buf, BUFFER_SIZE).LastRead();
      result += wxString((const char*)buf, wxCSConv(wxT("windows-1251")), bytesRead);
    } while (bytesRead == BUFFER_SIZE);

    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TSE_COMPLETED );
    event.SetString(result);
    event.SetInt(http.GetResponse());
    wxPostEvent( m_eventReceiver, event );

  } else {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TSE_ERROR );
    wxPostEvent( m_eventReceiver, event );
  }

  return NULL;
}

}
