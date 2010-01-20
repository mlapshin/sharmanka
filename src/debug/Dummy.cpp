#include <iostream>
#include <math.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <shr/ByteFlow.hpp>
#include <shr/MADWork.hpp>
#include <shr/PortAudio.hpp>

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
  if(argc < 2) {
    printf("usage: %s mp3file\n", argv[0]);
    return 1;
  }

  DummyByteFlow bf(argv[1]);
  shr::MADWork mw;
  shr::PortAudio pa;

  mw.Decode(bf, pa);
  return 0;

#if 0
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
