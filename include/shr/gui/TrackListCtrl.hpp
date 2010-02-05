#ifndef _TRACKLISTCTRL_H_
#define _TRACKLISTCTRL_H_

#include "wx/htmllbox.h"
#include "shr/TrackList.hpp"

namespace shr {
namespace gui {

class TrackListCtrl : public wxHtmlListBox, TrackListObserver
{
 public:
  TrackListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& s = wxDefaultSize, long unused_arg = 0); // TODO: remove unused style arg
  ~TrackListCtrl();

  void OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const;

  virtual void OnTracksSet(const TrackVector& newTracks);
  virtual void OnTracksAppended(const TrackVector& appendedTracks);

  inline void SetMoarLink(bool moar)
  {
    m_moarLink = moar;
  }

  inline TrackList* GetTrackList() const
  {
    return m_trackList;
  }

  void SetTrackList(TrackList* tl);

 protected:

  void OnLeftMouseDown( wxMouseEvent& event );
  void OnRightMouseDown(wxMouseEvent& event);
  void OnLeftMouseDClick(wxMouseEvent& event);
  void OnMenuCopyTrackUrl(wxCommandEvent& event);

  void UpdateList(int upTo);

  virtual wxString OnGetItem(size_t n) const;

  bool m_moarLink;
  TrackList* m_trackList;

  DECLARE_EVENT_TABLE()
};

}}

#endif /* _TRACKLISTCTRL_H_ */
