#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackListCtrl.hpp"
#include "wx/clipbrd.h"
#include "shr/gui/MainWindow.hpp"

namespace shr {
namespace gui {

enum {
  POPUP_COPY_URL
};

BEGIN_EVENT_TABLE(TrackListCtrl, wxHtmlListBox)
  EVT_RIGHT_DOWN(TrackListCtrl::OnRightMouseDown)
  EVT_LEFT_DCLICK(TrackListCtrl::OnLeftMouseDClick)
  EVT_LEFT_DOWN(TrackListCtrl::OnLeftMouseDown)
END_EVENT_TABLE()

TrackListCtrl::TrackListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& s, long style)
    : wxHtmlListBox(parent, id, pos, s, wxSUNKEN_BORDER), m_moarLink(false)
{
  SetMargins(3, 3);
  m_trackList = 0;
  // SetTracks(m_tracks);
}

TrackListCtrl::~TrackListCtrl()
{

}

void TrackListCtrl::OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const
{
  const bool isMoarBtn = (m_moarLink && n == m_trackList->GetTracksCount());
  const bool isSelected = (IsSelected(n) && !isMoarBtn),
      isCurrent = (IsCurrent(n) && !isMoarBtn),
      isOdd = (n % 2 != 0);

  if ( isSelected || isCurrent || isOdd ) {
    dc.SetBrush(wxBrush((!isSelected && isOdd) ? wxColour(_T("#fafafa")) : GetSelectionBackground(), wxSOLID));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(rect);
  }
}

void TrackListCtrl::UpdateList(int from)
{
  wxASSERT(m_trackList);
  size_t oldScrollPos = GetFirstVisibleLine();
  size_t listItemsCount = m_trackList->GetTracksCount() + (m_moarLink ? 1 : 0);

  if(m_trackList->GetTracksCount() == 0) {
    Disable();
  } else if(!IsEnabled()) {
    Enable();
  }

  SetItemCount(listItemsCount);
  ScrollToLine(oldScrollPos + 1);
  RefreshLines(from, listItemsCount);
}

void TrackListCtrl::SetTrackList(TrackList* tl)
{
  wxASSERT(m_trackList == 0);
  m_trackList = tl;
  wxASSERT(m_trackList != 0);

  m_trackList->AddObserver(this);
  UpdateList(0);
}

void TrackListCtrl::OnTracksAppended(const TrackVector& newTracks)
{
  UpdateList(m_trackList->GetTracksCount() - newTracks.size());
}

void TrackListCtrl::OnTracksSet(const TrackVector& newTracks)
{
  UpdateList(0);
}

void TrackListCtrl::SetMoarLink(bool moar)
{
  m_moarLink = moar;
  UpdateList(m_trackList->GetTracksCount());
}

wxString TrackListCtrl::OnGetItem(size_t n) const
{
  wxString ret;

  if (m_trackList != 0 && m_trackList->GetTracksCount() > n) {
    wxString d;
    d.Printf(_T("%d:%.2d"), m_trackList->GetTrack(n)->GetDuration() / 60, m_trackList->GetTrack(n)->GetDuration() % 60);

    wxString playIcon = _T("<td width=18 valign=top>");
    if (n == 5 || n == 8) playIcon += _T("<img src='bitmaps/icons/control.png' border=0>");
    playIcon += _T("</td>");

    ret = _T("<table width=100% cellpadding=0 cellspacing=0><tr>") +
        playIcon +
        _T("<td><B>") +
        m_trackList->GetTrack(n)->GetArtist() + _T("</B> &mdash; ") + m_trackList->GetTrack(n)->GetTitle() +
        _T("</td><td align=right valign=top width=70><font color=#666>") + d +
        _T("&nbsp;</font></td></tr></table>");

  } else if (m_trackList == 0 || m_trackList->GetTracksCount() == 0) {
    // Sorry nothing found message
    ret = _T("<br><center><font color=#aaa size=+1><b>Либо Вы еще ничего не искали, либо по Вашему запросу ничего не найдено</b></font></center>");
  } else if (m_trackList != 0 && m_trackList->GetTracksCount() == n && m_moarLink) {
    // MOAR link
    ret = _T("<center><a href=\"#\"><b>Еще музыки!</b></a></center>");
  }

  return ret;
}

void TrackListCtrl::OnRightMouseDown(wxMouseEvent& event)
{
  SetFocus();

  int item = HitTest(event.GetPosition());

  if(m_trackList == 0 || m_trackList->GetTracksCount() <= item) {
    return;
  }

  if (item != wxNOT_FOUND) {
    DoHandleItemClick(item, 0);

    wxMenu mnu;
    mnu.SetClientData(reinterpret_cast<void*>(m_trackList->GetTrack(item)));
    mnu.Append(-1, _T("Копировать URL файла"));
    mnu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxObjectEventFunction(&TrackListCtrl::OnMenuCopyTrackUrl), NULL, this);
    PopupMenu(&mnu);
  }
}

void TrackListCtrl::OnLeftMouseDClick(wxMouseEvent& event)
{
  // TODO: play track here
}

void TrackListCtrl::OnMenuCopyTrackUrl(wxCommandEvent& event)
{
  Track* t = reinterpret_cast<Track*>(static_cast<wxMenu *>(event.GetEventObject())->GetClientData());

  if (wxTheClipboard->Open()) {
    wxTheClipboard->SetData(new wxTextDataObject(t->GetFileURL()));
    wxTheClipboard->Close();
  }
}

void TrackListCtrl::OnLeftMouseDown(wxMouseEvent& event)
{
  int item = HitTest(event.GetPosition());
  if(m_trackList == 0 || (!m_moarLink && m_trackList->GetTracksCount() <= item)) {
    return;
  }

  if (item != wxNOT_FOUND && item == m_trackList->GetTracksCount()) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TLE_MOAR_TRACKS );
    GetEventHandler()->ProcessEvent( event );
  } else {
    event.Skip();
  }

}


}}
