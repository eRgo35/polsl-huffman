#include <iostream>
#include "defs.h"

void sort_tab(int *arr, int len)
{
  int minI = 0;
  int tmp = arr[0];

  for (int i = 0; i < len; i++)
  {
    int min = arr[i];
    for (int j = i; j < len; j++)
    {

      if (min > arr[j])
      {
        min = arr[j];
        minI = j;
      }
    }
    int tmp = arr[i];
    arr[i] = min;
    arr[minI] = tmp;
  }
}