#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

namespace shr {

class TrackList {

 public:
  void SetTracks(const TrackVector& newTracks);
  void AppendTracks(const TrackVector& tracksToAppend);

 private:
  TrackVector m_tracks;
};

}

#endif /* _TRACKLIST_H_ */
