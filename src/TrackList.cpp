#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackList.hpp"

namespace shr {
namespace gui {

TrackList::TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& s, long style)
    : wxHtmlListBox(parent, id, pos, s, wxSUNKEN_BORDER)
{
  SetItemCount(100);
  SetMargins(3, 3);
}

TrackList::~TrackList()
{

}

wxString TrackList::OnGetItem(size_t n) const
{
  return _T("<table width=100% cellpadding=0 cellspacing=0><tr><td><B>Гражданская Оборона</B> &mdash; Все идет по плану</td><td align=right>3:12</td></tr></table>");
}

}}
