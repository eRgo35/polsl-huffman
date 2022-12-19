//
//  funkcje.cpp
//  projekt_ex
//
//  Created by Agnieszka Danek on 01/12/2021.
//

#include <iostream>
#include "funkcje.h"

// f(x)=x
double f1(double x)
{
  return x;
}

// f(x)=x*x
double f2(double x)
{
  return x * x;
}

// całkowanie numeryczne funkcji fun w prezedziale [a,b] (całka oznaczona)
double calk_num(double a, double b, double (*fun)(double))
{
  double area = 0;
  while (a < b)
  {
    area += fun(a);
    a += 0.01;
  }
  return fun(area)/100;
}
