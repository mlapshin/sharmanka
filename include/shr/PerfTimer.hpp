#ifndef _PERFTIMER_HPP_
#define _PERFTIMER_HPP_

// perftimer is very simple, it works with
// sub-second intervals only

#include <time.h>

namespace shr
{
  class PerfTimer
  {
    public:
      PerfTimer(const char *t_name);
      ~PerfTimer();
      void Start(void);
      void Stop(void);
    private:
      struct timespec ts_start, ts_stop;
      const char *name;
      double max, min;
  };
};

#endif
