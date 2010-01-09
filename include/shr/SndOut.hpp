#ifndef _SNDOUT_HPP_
#define _SNDOUT_HPP_

// sound output, yes, really
namespace shr {
  class SndOut {
    public:
      virtual int Play(unsigned int samples, const unsigned char *pbuf) = 0;
  };
}

#endif
