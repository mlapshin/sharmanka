#ifndef _PORTAUDIO_HPP_
#define _PORTAUDIO_HPP_

// sound output via PortAudio cross-platform library

#include <portaudiocpp/PortAudioCpp.hxx>
#include <shr/SndOut.hpp>
#include <cstdio>

namespace shr {
  class PortAudio : public SndOut {
    private:
      portaudio::AutoSystem autosys;
      portaudio::BlockingStream stream;
      FILE *fp;
      unsigned int errors;
    public:
      PortAudio();
      ~PortAudio();
      int Play(unsigned int samples, const void *pdata);
  };
}

#endif
