#include <iostream>
#include <cstring>
#include <cstdio>
#include <mad.h>
#include <limits.h>
#include <shr/MADWork.hpp>

namespace shr
{

// that conversion routine seems rather accurate
// thanks to MPD mp3 decoder developers 
static inline short
mad_fixed_to_sample(mad_fixed_t sample)
{
  enum {
    bits = 16,
    MIN = -MAD_F_ONE,
    MAX = MAD_F_ONE - 1
  };
  /* round */
  sample = sample + (1L << (MAD_F_FRACBITS - bits));
  /* clip */
  if (sample > MAX)
    sample = MAX;
  else if (sample < MIN)
    sample = MIN;
  /* quantize */
  return sample >> (MAD_F_FRACBITS + 1 - bits);
}

MADWork::MADWork()
{
  std::cerr << "libmad codec stuff init" << std::endl;
  mad_stream_init(&st);
  mad_stream_options(&st, MAD_OPTION_IGNORECRC);
  mad_frame_init(&fr);
  mad_synth_init(&synth);
}

MADWork::~MADWork() 
{
  std::cerr << "MADWork destructed" << std::endl;
  mad_synth_finish(&synth);
  mad_frame_finish(&fr);
  mad_stream_finish(&st);
}

int MADWork::Decode(ByteFlow &flow, SndOut &out)
{
  int res = 0, to_decode = 0, filled = 0;
  unsigned char *rs = in_buf;
  unsigned int samples = 0;
  do {
    if(!st.buffer || st.error == MAD_ERROR_BUFLEN) {
      size_t prefilled = 0, to_read = MADWork::in_size;
      rs = in_buf;

      if(st.next_frame) {
	// last frame was not decoded fully
	size_t to_move = st.bufend - st.next_frame;
	memmove(in_buf, st.next_frame, to_move);
	to_read -= to_move;
	rs += to_move;
	prefilled = to_move;
      }

      filled = flow.Read(to_read, rs);
      if(filled == -1) {
	std::cerr << "MADWork::Decode: flow.Read failed" << std::endl;
	filled = 0;
	res = -1;
      }

      // TODO: MAP_BUFFER_GUARD crap

      to_decode = prefilled + filled;
      mad_stream_buffer(&st, in_buf, to_decode);
    }

    if(to_decode > 0) {
      st.error = MAD_ERROR_NONE;
      int d_res;
      d_res = mad_frame_decode(&fr, &st);
      if(d_res) {
	if(st.error == MAD_ERROR_BUFLEN) {
	  // more data needed, restart
	  continue;
	}
	if(st.error == MAD_ERROR_LOSTSYNC) {
	  int res = mad_stream_sync(&st);
	  std::cerr << "--- MADWork::Decode: mad_stream_sync() returned " << res << std::endl;
	  continue;
	}
	if(MAD_RECOVERABLE(st.error)) {
	  // we probably need some error handling here
	  continue;
	}
	return -1;
      }
      mad_synth_frame(&synth, &fr);

      for(unsigned int sn = 0; sn < synth.pcm.length; sn++) {
	out_buf[samples++] = mad_fixed_to_sample(synth.pcm.samples[0][sn]);
	if(MAD_NCHANNELS(&fr.header) == 2) {
	  out_buf[samples++] = mad_fixed_to_sample(synth.pcm.samples[1][sn]);
	}
	if(samples >= MADWork::out_size) {
	  res = out.Play(samples/2, out_buf);
	  if(res)
	    return res;
	  samples = 0;
	}
      }
      //if(samples > 0)
      //out.Play(samples/2, out_buf);

    }
  } while(filled > 0);

  if(samples > 0)
	res = out.Play(samples/2, out_buf);

  return res;
}

}
