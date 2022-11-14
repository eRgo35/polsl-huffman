#include "defs.h"

double max(double a, double b, double c)
{
  double m[3] = {a, b, c};
  double t = m[0];
  for (int i = 0; i < 3; i++)
  {
    if (m[i] > t) {
      t = m[i];
    }
  }
  return t;
}