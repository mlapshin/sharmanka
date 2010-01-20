#include <iostream>
#include <cstdio>
#include <time.h>
#include <shr/PortAudio.hpp>

#include <shr/PerfTimer.hpp>

shr::PerfTimer inner("player"), outer("mad");

shr::PortAudio::PortAudio() {
  std::cerr << "sharmanka will rock via PortAudio" << std::endl;
  errors = 0;

  portaudio::System &sys = portaudio::System::instance();

  portaudio::DirectionSpecificStreamParameters outParams(sys.defaultOutputDevice(), 2, portaudio::INT16, true, sys.defaultOutputDevice().defaultLowOutputLatency(), NULL);	
  portaudio::StreamParameters params(portaudio::DirectionSpecificStreamParameters::null(), outParams, 44100.0, 1024, paClipOff);

  outer.Start();
  stream.open(params);
  stream.start();
}

shr::PortAudio::~PortAudio() {
  std::cerr << "epic fail, for " << errors << " times..." << std::endl;
  std::cerr << "closing PortAudio..." << std::endl;
  stream.close();
}

int shr::PortAudio::Play(unsigned int samples, const void *data) {
  std::cerr << "PortAudio::Play samples " << samples << std::endl;
  outer.Stop();

  inner.Start();
  try {
    stream.write(data, samples);
  }
  catch(portaudio::PaException ex) {
    inner.Stop();
    std::cerr << "PortAudio::Play broken, " << ex.paErrorText() << std::endl;
    std::cerr << "PortAudio::Play avaliable frames " << stream.availableWriteSize() << std::endl;
    errors++;
    return -1;
  }
  inner.Stop();

  outer.Start();
  return 0;
}
