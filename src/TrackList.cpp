#include "shr/Prerequisites.hpp"
#include "shr/TrackList.hpp"

namespace shr {

TrackList::TrackList()
{

}

TrackList::~TrackList()
{

}

void TrackList::SetTracks(const TrackVector& newTracks)
{
  m_tracks.clear();
  m_tracks = newTracks;

  for(TrackListObserverList::iterator i = m_observers.begin(); i != m_observers.end(); i++) {
    (*i)->OnTracksSet(newTracks);
  }
}

void TrackList::AppendTracks(const TrackVector& newTracks)
{
  m_tracks.insert(m_tracks.begin() + m_tracks.size(), newTracks.begin(), newTracks.end());

  for(TrackListObserverList::iterator i = m_observers.begin(); i != m_observers.end(); i++) {
    (*i)->OnTracksAppended(newTracks);
  }
}

void TrackList::AddObserver(TrackListObserver* observer)
{
  m_observers.push_back(observer);
}

} // namespace shr
