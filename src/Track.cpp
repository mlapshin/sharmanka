#include "shr/Prerequisites.hpp"
#include "shr/Track.hpp"

namespace shr
{

Track::Track(const wxString& artist, const wxString& title, int duration, const wxString& serverId, const wxString& userId, const wxString& fileName)
    : m_artist(artist), m_title(title), m_duration(duration), m_serverId(serverId), m_userId(userId), m_fileName(fileName)
{

}

Track::Track(const Track& track)
    : m_artist(track.GetArtist()), m_title(track.GetTitle()), m_duration(track.GetDuration()), m_serverId(track.GetServerId()), m_userId(track.GetUserId()), m_fileName(track.GetFileName())
{

}

const Track& Track::operator=(const Track& t)
{
  m_artist = t.GetArtist();
  m_title = t.GetTitle();
  m_duration = t.GetDuration();
  m_serverId = t.GetServerId();
  m_userId = t.GetUserId();
  m_fileName = t.GetFileName();

  return *this;
}

}
