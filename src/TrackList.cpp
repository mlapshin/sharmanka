#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackList.hpp"
#include "wx/clipbrd.h"
#include "shr/gui/MainWindow.hpp"

namespace shr {
namespace gui {

enum {
  POPUP_COPY_URL
};

BEGIN_EVENT_TABLE(TrackList, wxHtmlListBox)
  EVT_RIGHT_DOWN(TrackList::OnRightMouseDown)
  EVT_LEFT_DCLICK(TrackList::OnLeftMouseDClick)
  EVT_LEFT_DOWN(TrackList::OnLeftMouseDown)
END_EVENT_TABLE()

TrackList::TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& s, long style)
    : wxHtmlListBox(parent, id, pos, s, wxSUNKEN_BORDER)
{
  SetMargins(3, 3);
  SetTracks(m_tracks);
}

TrackList::~TrackList()
{

}

void TrackList::OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const
{
  const bool isMoarBtn = (n == m_tracks.size());
  const bool isSelected = (IsSelected(n) && !isMoarBtn),
      isCurrent = (IsCurrent(n) && !isMoarBtn),
      isOdd = (n % 2 != 0);

  if ( isSelected || isCurrent || isOdd ) {
    dc.SetBrush(wxBrush((!isSelected && isOdd) ? wxColour(_T("#fafafa")) : GetSelectionBackground(), wxSOLID));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(rect);
  }
}

void TrackList::UpdateMe()
{
  if (m_tracks.size() == 0) {
    SetItemCount(1);
    Disable();
  } else {
    SetItemCount(m_tracks.size() + 1);
    Enable();
  }

  RefreshAll();
}

void TrackList::SetTracks(const TrackVector& newTracks)
{
  m_tracks = newTracks;
  UpdateMe();
}

void TrackList::AppendTracks(const TrackVector& newTracks)
{
  size_t oldCount = m_tracks.size();
  m_tracks.insert(m_tracks.begin() + m_tracks.size(), newTracks.begin(), newTracks.end());
  SetItemCount(m_tracks.size() + 1);
  ScrollToLine(oldCount);
  RefreshLines(oldCount, m_tracks.size() + 1);
}

wxString TrackList::OnGetItem(size_t n) const
{
  wxString ret;

  if (m_tracks.size() > n) {
    wxString d;
    d.Printf(_T("%d:%.2d"), m_tracks[n].GetDuration() / 60, m_tracks[n].GetDuration() % 60);

    ret = _T("<table width=100% cellpadding=0 cellspacing=0><tr><td><B>") +
        m_tracks[n].GetArtist() + _T("</B> &mdash; ") + m_tracks[n].GetTitle() +
        _T("</td><td align=right valign=top><font color=#666>") + d +
        _T("&nbsp;</font></td></tr></table>");

  } else if (m_tracks.size() == 0) {
    ret = _T("<br><center><font color=#aaa size=+2><b>Либо Вы еще ничего не искали, либо по Вашему запросу ничего не найдено</b></font></center>");
  } else if (m_tracks.size() == n) {
    ret = _T("<center><a href=\"#\"><b>Еще музыки!</b></a></center>");
  }

  return ret;
}

void TrackList::OnRightMouseDown(wxMouseEvent& event)
{
  SetFocus();

  int item = HitTest(event.GetPosition());

  if (item != wxNOT_FOUND) {
    DoHandleItemClick(item, 0);

    wxMenu mnu;
    mnu.SetClientData(&m_tracks[item]);
    mnu.Append(-1, _T("Копировать URL файла"));
    mnu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxObjectEventFunction(&TrackList::OnMenuCopyTrackUrl), NULL, this);
    PopupMenu(&mnu);
  }
}

void TrackList::OnLeftMouseDClick(wxMouseEvent& event)
{
  // TODO: play track here
}

void TrackList::OnMenuCopyTrackUrl(wxCommandEvent& event)
{
  Track* t = reinterpret_cast<Track*>(static_cast<wxMenu *>(event.GetEventObject())->GetClientData());

  if (wxTheClipboard->Open()) {
    wxTheClipboard->SetData(new wxTextDataObject(t->GetFileURL()));
    wxTheClipboard->Close();
  }
}

void TrackList::OnLeftMouseDown(wxMouseEvent& event)
{
  int item = HitTest(event.GetPosition());

  if (item != wxNOT_FOUND && item == m_tracks.size()) {
    // MOAR link clicked here
    // TODO: refactor this shit
    MainWindow* mw = reinterpret_cast<MainWindow*>(this->GetParent());
    mw->QueryMoreTracks();
    event.StopPropagation();
  } else {
    event.Skip();
  }

}


}}
