#ifndef _TRACK_H_
#define _TRACK_H_

#include <vector>

namespace shr
{

class Track
{
 public:
  Track(const wxString& artist, const wxString& title, int duration, const wxString& serverId, const wxString& userId, const wxString& fileName);
  Track(const Track& trck);
  ~Track() {}

  inline const wxString& GetArtist() const
  {
    return m_artist;
  }

  inline const wxString& GetTitle() const
  {
    return m_title;
  }

  inline int GetDuration() const
  {
    return m_duration;
  }

  inline const wxString& GetServerId() const
  {
    return m_serverId;
  }

  inline const wxString& GetUserId() const
  {
    return m_userId;
  }

  inline const wxString& GetFileName() const
  {
    return m_fileName;
  }

  inline wxString GetFileURL() const
  {
    return _T("http://cs") + m_serverId + _T(".vkontakte.ru/u") + m_userId + _T("/audio/") + m_fileName + _T(".mp3");
  }

  const Track& operator=(const Track& rhs);

 private:
  wxString m_artist;
  wxString m_title;

  int m_duration;
  wxString m_serverId;
  wxString m_userId;
  wxString m_fileName;
};

typedef std::vector<Track> TrackVector;

}

#endif /* _TRACK_H_ */
