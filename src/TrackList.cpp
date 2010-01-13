#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackList.hpp"

namespace shr {
namespace gui {

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
  // we need to render selected and current items differently
  const bool isSelected = IsSelected(n),
      isCurrent = IsCurrent(n),
      isOdd = (n % 2 != 0);

  if ( isSelected || isCurrent || isOdd ) {
    dc.SetBrush(wxBrush((!isSelected && isOdd) ? wxColour(_T("#fafafa")) : GetSelectionBackground(), wxSOLID));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(rect);
  }
}

void TrackList::SetTracks(const TrackVector& newTracks)
{
  m_tracks = newTracks;
  if (newTracks.size() == 0) {
    SetItemCount(1);
    Disable();
  } else {
    SetItemCount(m_tracks.size());
    Enable();
  }

  RefreshAll();
}

wxString TrackList::OnGetItem(size_t n) const
{
  wxString ret;
  if (m_tracks.size() > n) {
    wxString d;
    d.Printf(_T("%d:%.2d"), m_tracks[n].GetDuration() / 60, m_tracks[n].GetDuration() % 60);

    // wxString bgcolor = (n % 2 != 0) ? _T("  bgcolor=#f0f0f0") : _T("");

    ret = _T("<table width=100% cellpadding=0 cellspacing=0><tr><td><B>") +
        m_tracks[n].GetArtist() + _T("</B> &mdash; ") + m_tracks[n].GetTitle() +
        _T("</td><td align=right valign=top><font color=#666>") + d +
        _T("&nbsp;</font></td></tr></table>");

  } else {
    ret = _T("<br><center><font color=#aaa size=+2><b>Либо Вы еще ничего не искали, либо по Вашему запросу ничего не найдено</b></font></center>");
  }

  return ret;
}

}}
