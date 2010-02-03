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
      void SetIn(size_t n, void *ptr) { // bytes
	in_size = n;
	in_buf = static_cast<unsigned char *>(ptr);
      }
      void SetOut(size_t n, void *ptr) { // samples
	out_size = n;
	out_buf = static_cast<signed short *>(ptr);
      }
      int Decode(ByteFlow &, SndOut &);

    private:
      struct mad_stream st;
      struct mad_frame fr;
      struct mad_synth synth;
      size_t in_size;
      size_t out_size;
      unsigned char *in_buf;
      signed short *out_buf;
  };
};

#endif
