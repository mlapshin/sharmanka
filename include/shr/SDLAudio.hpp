#ifndef _SDLAUDIO_HPP_
#define _SDLAUDIO_HPP_

#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_thread.h>

#include <time.h>

#include <shr/SndOut.hpp>

namespace shr {
  class SDLAudio : public SndOut {
    public:
      SDLAudio();
      ~SDLAudio();
      int Open(unsigned freq, unsigned samples, void *pbuf); 
      int Play(unsigned samples, const void *pbuf);
      unsigned GetSamplesCount(void);
      void ProcessCallback(Uint8 *stream, int len);
      
    private:
      SDL_AudioSpec fmt;
      SDL_cond *cond;
      SDL_mutex *mut;
      void *udata;
  };
};

#endif
