#ifndef TIME_H
#define TIME_H

/**
 * @brief struktura opisująca czas w schemacie godzina, minuta, sekunda
 * 
 */
struct Time
{
  int hours, minutes, seconds;
};

/**
 * @brief dodaje drugi czas do pierwszego
 * 
 * @param time1 
 * @param time2 
 */
void add_time(Time &time1, Time &time2);

/**
 * @brief odejmuje drugi czas od pierwszego
 * 
 * @param time1 
 * @param time2 
 */
void sub_time(Time &time1, Time &time2);

#endif