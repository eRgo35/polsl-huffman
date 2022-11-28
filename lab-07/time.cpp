#include <iostream>

#include "time.h"

void add_time(Time &time1, Time &time2)
{
  if ((time1.seconds += time2.seconds) >= 60)
  {
    time1.seconds %= 60;
    time1.minutes++;
  }

  if ((time1.minutes += time2.minutes) >= 60)
  {
    time1.minutes %= 60;
    time1.hours++;
  }

  if ((time1.hours += time2.hours) >= 24)
  {
    time1.hours %= 24;
  }
}

void sub_time(Time &time1, Time &time2)
{
  if ((time1.seconds -= time2.seconds) < 0)
  {
    time1.seconds += 60;
    time1.minutes--;
  }

  if ((time1.minutes -= time2.minutes) < 0)
  {
    time1.minutes += 60;
    time1.hours--;
  }

  if ((time1.hours += time2.hours) < 0)
  {
    time1.hours += 24;
  }
}