#ifndef _MADWORK_HPP_
#define _MADWORK_HPP_

// MADWork is a thin C++ stuff around libmad library
// no other codecs will be, at least for some time

#include <cstddef>
#include <shr/ByteFlow.hpp>
#include <shr/SndOut.hpp>
#include <mad.h>

namespace shr
{
  class MADWork
  {
    public:
      MADWork();
      ~MADWork();
      int Decode(ByteFlow &, SndOut &);

    private:
      struct mad_stream st;
      struct mad_frame fr;
      struct mad_synth synth;
      static const size_t in_size = 4*8192;
      static const size_t out_size = 8192;
      unsigned char in_buf[in_size];
      char out_buf[out_size];
  };
};

#endif