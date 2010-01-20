#include <cstdio>
#include <shr/PerfTimer.hpp>

shr::PerfTimer::PerfTimer(const char *pt_name) : name(pt_name), min(0), max(0) {
}

shr::PerfTimer::~PerfTimer() {
  fprintf(stderr, "PerfTimer::~PerfTimer \"%s\", min = %f, max = %f\n", name, min, max);
}

void shr::PerfTimer::Start() {
  clock_gettime(CLOCK_REALTIME, &ts_start);
}

void shr::PerfTimer::Stop() {
  double period;
  clock_gettime(CLOCK_REALTIME, &ts_stop);
  if(ts_start.tv_sec == ts_stop.tv_sec)
    period = (double)(ts_stop.tv_nsec - ts_start.tv_nsec) / 1000000000.;
  else
    period = (double)(1000000000 - ts_start.tv_nsec + ts_stop.tv_nsec) / 1000000000.;

  if(max == 0) max = min = period;
  if(period > max)
    max = period;
  else if(period < min)
    min = period;

  fprintf(stderr, "PerfTimer::Stop \"%s\", measured %f sec\n", name, period);
}
