#include "shr/Prerequisites.hpp"
#include "shr/gui/TrackList.hpp"

namespace shr {
namespace gui {

TrackList::TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& s, long style)
    : wxListCtrl(parent, id, pos, s, wxLC_REPORT | wxSUNKEN_BORDER | wxVSCROLL)
{
  wxListItem header;
  header.SetText(_T("Band"));
  header.SetWidth(wxLIST_AUTOSIZE);
  InsertColumn(0, header);

  header.SetText(_T("Song"));
  InsertColumn(1, header);

  header.SetText(_T("Length"));
  header.SetAlign(wxLIST_FORMAT_RIGHT);
  InsertColumn(2, header);

  for(int i = 0; i < 50; i++) {
    wxString buf;
    wxListItem item;

    buf.Printf(_T("Band #%d"), i);
    item.SetText(buf);
    long foo = InsertItem(item);

    buf.Printf(_T("Track #%d"), i);
    SetItem(foo, 1, buf);

    buf.Printf(_T("03:12"), i);
    SetItem(foo, 2, buf);
  }
}

TrackList::~TrackList()
{

}

}}
