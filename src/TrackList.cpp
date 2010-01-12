#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackList.hpp"

namespace shr {
namespace gui {

TrackList::TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& s, long style)
    : wxHtmlListBox(parent, id, pos, s, wxSUNKEN_BORDER)
{
  SetMargins(3, 3);
}

TrackList::~TrackList()
{

}

void TrackList::OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const
{
  // we need to render selected and current items differently
  const bool isSelected = IsSelected(n),
      isCurrent = IsCurrent(n);
  if ( isSelected || isCurrent ) {
    dc.SetBrush(wxBrush(GetSelectionBackground(), wxSOLID));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(rect);
  }
}

void TrackList::SetTracks(const TrackVector& newTracks)
{
  m_tracks = newTracks;
  SetItemCount(m_tracks.size());
  RefreshAll();
}

wxString TrackList::OnGetItem(size_t n) const
{
  wxString d;
  d.Printf(_T("%d:%.2d"), m_tracks[n].GetDuration() / 60, m_tracks[n].GetDuration() % 60);

  wxString ret = _T("<table width=100% cellpadding=0 cellspacing=0><tr><td><B>") +
      m_tracks[n].GetArtist() + _T("</B> &mdash; ") + m_tracks[n].GetTitle() +
      _T("</td><td align=right valign=top><font color=#666>") + d +
      _T("&nbsp;</font></td></tr><tr><td colspan=2><font color=#666 size=-2>") +
      m_tracks[n].GetFileURL() +
      _T("</font></td></tr></table>");

  return ret;
}

}}
