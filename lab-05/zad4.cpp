#include "defs.h"

void my_swap(int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}