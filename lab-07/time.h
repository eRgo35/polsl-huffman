#ifndef TIME_H
#define TIME_H

struct Time
{
  int hours, minutes, seconds;
};

void add_time(Time &time1, Time &time2);

void sub_time(Time &time1, Time &time2);

#endif