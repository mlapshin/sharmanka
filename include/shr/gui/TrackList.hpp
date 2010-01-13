#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

#include "wx/htmllbox.h"
#include "shr/Track.hpp"
#include <vector>

namespace shr {
namespace gui {

class TrackList : public wxHtmlListBox
{
 public:
  TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& s = wxDefaultSize, long unused_arg = 0); // TODO: remove unused style arg
  ~TrackList();

  void SetTracks(const TrackVector& newTracks, bool moar = true);
  void AppendTracks(const TrackVector& newTracks, bool moar = true);

  void OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const;

  inline const TrackVector& GetTracks() const
  {
    return m_tracks;
  }

 protected:

  void OnLeftMouseDown( wxMouseEvent& event );
  void OnRightMouseDown(wxMouseEvent& event);
  void OnLeftMouseDClick(wxMouseEvent& event);
  void OnMenuCopyTrackUrl(wxCommandEvent& event);

  virtual wxString OnGetItem(size_t n) const;

  TrackVector m_tracks;
  bool m_moarLink;

  DECLARE_EVENT_TABLE()
};

}}

#endif /* _TRACKLIST_H_ */
