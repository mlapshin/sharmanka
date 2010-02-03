#include <iostream>
#include <math.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <shr/ByteFlow.hpp>
#include <shr/MADWork.hpp>
#include <shr/SDLAudio.hpp>

class DummyByteFlow : public ByteFlow {
  private:
    int fd;
  public:
    DummyByteFlow(char *file) {
      fd = open(file, O_RDONLY);
      if(fd == -1)
	std::cerr << "DummyByteFlow: unable to open file" << std::endl;
    }
    ~DummyByteFlow() { close(fd); }
    int Read(unsigned int length, unsigned char *pdata) {
      int res = read(fd, pdata, length);
      if(res == -1)
	std::cerr << "DummyByteFlow: read failed" << std::endl;
      return res;
    }
};


int main(int argc, char *argv[]) {
  int res;
  
  if(argc < 2) {
    printf("usage: %s mp3file\n", argv[0]);
    return 1;
  }

  DummyByteFlow bf(argv[1]);

  shr::SDLAudio au;

  const unsigned in_size = 32*1024; // bytes
  const unsigned out_size = 4096;   // samples 
  unsigned char in_buf[in_size];
  signed short out_buf[out_size][2];

  res = au.Open(44100, out_size, out_buf);
  if(res)
    return 1;

  unsigned r_out_size = au.GetSamplesCount();
  if(r_out_size > out_size) {
    printf("%s: sound output set buffer size %d "
	" but we have only %d...\n", argv[0], r_out_size, out_size);
    return 1;
  }

  shr::MADWork mw;
  mw.SetIn(in_size, in_buf);
  mw.SetOut(r_out_size, out_buf);

  mw.Decode(bf, au);

  return 0;

#if 0

  return 0;

  int i, j;
#define buf_size (2000)
#define chunk_size (200)
#define seconds (1)
#define cycles ((seconds*44100)/(buf_size))
  short fbuf[buf_size*2];

  for(j = 0; j < buf_size*2; j+=chunk_size*2) {
    for(i = 0; i < chunk_size*2; i+=2) {
      //fbuf[i+j][0] = ((float) sin( ((double)i/(double)chunk_size) * M_PI * 4. )) * 5000 ;
      fbuf[i+j] = ((float) sin( ((double)i/(double)chunk_size) * M_PI * 2. )) * 10000 ;
      fbuf[i+j+1] = 0;
    }
  }

 for(i = 0; i < cycles; i++) 
    pa.Play(buf_size, fbuf);
  
  return 0;
#endif
}
