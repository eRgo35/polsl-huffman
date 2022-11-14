#include <iostream>
#include <vector>

void print_vec(const std::vector<int> &v) 
{
  for (auto a : v)
  {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}