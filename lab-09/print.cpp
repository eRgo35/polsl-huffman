#include <iostream>
#include <vector>
#include <list>
#include <set>

#include "print.h"

void print(std::vector<int> wektor)
{
  std::cout << "[ ";
  for (int w : wektor)
    std::cout << w << " ";
  std::cout << "]" << std::endl;
}

void print(std::list<int> &list)
{
  std::cout << "[ ";
  for (int l : list)
    std::cout << l << " ";
  std::cout << "]" << std::endl;
}

void print(std::set<int> &set)
{
  std::cout << "[ ";
  for (int s : set)
    std::cout << s << " ";
  std::cout << "]" << std::endl;
}