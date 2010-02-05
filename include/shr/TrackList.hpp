#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

#include "shr/Track.hpp"
#include <list>

namespace shr {

class TrackListObserver;
typedef std::list<TrackListObserver*> TrackListObserverList;

class TrackList {
 public:

  TrackList();
  ~TrackList();

  void SetTracks(const TrackVector& newTracks);
  void AppendTracks(const TrackVector& tracksToAppend);

  inline Track* GetTrack(int index)
  {
    return &m_tracks[index];
  }

  inline const Track* GetTrack(int index) const
  {
    return &m_tracks[index];
  }

  inline size_t GetTracksCount() const
  {
    return m_tracks.size();
  }

  void AddObserver(TrackListObserver* observer);

 private:
  TrackVector m_tracks;
  TrackListObserverList m_observers;
};

class TrackListObserver
{
 public:
  virtual void OnTracksSet(const TrackVector& newTracks) {}
  virtual void OnTracksAppended(const TrackVector& appendedTracks) {}
};

}

#endif /* _TRACKLIST_H_ */
