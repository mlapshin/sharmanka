#include <cstdio>
#include <cstring>
#include <iostream>
#include <shr/SDLAudio.hpp>

shr::SDLAudio::SDLAudio() {
  SDL_Init(SDL_INIT_AUDIO);
  mut = SDL_CreateMutex();
  cond = SDL_CreateCond();
}

shr::SDLAudio::~SDLAudio() {
  SDL_DestroyCond(cond);
  SDL_DestroyMutex(mut);
  SDL_Quit();
}

static void cb(void *data, Uint8 *stream, int len) {
  //fprintf(stderr, "cb: data = %08x, stream = %08x, len = %d\n", data, stream, len);
  shr::SDLAudio *p_au = (shr::SDLAudio *)data;
  p_au->ProcessCallback(stream, len);
}

void shr::SDLAudio::ProcessCallback(Uint8 *stream, int len) {
  memcpy(stream, udata, len);
  SDL_CondSignal(cond);
}

int shr::SDLAudio::Open(unsigned freq, unsigned samples, void *buf) {
  int res;

  udata = buf;
  
  fmt.freq = freq; 
  fmt.format = AUDIO_S16LSB;
  fmt.channels = 2;
  fmt.samples = samples;
  fmt.callback = cb;
  fmt.userdata = this;

  res = SDL_OpenAudio(&fmt, NULL);
  if(res < 0) {
    std::cerr << "SDLAudio::Open failed, "
      << SDL_GetError() << std::endl;
    return -1;
  }

  SDL_LockMutex(mut);

  return 0;
}

int shr::SDLAudio::Play(unsigned int samples, const void *pbuf) {
  SDL_PauseAudio(0);
  SDL_CondWait(cond, mut);
  SDL_LockMutex(mut);
  return 0;
}

unsigned shr::SDLAudio::GetSamplesCount(void) {
  return fmt.samples;
}
