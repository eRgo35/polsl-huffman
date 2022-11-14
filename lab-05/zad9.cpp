#include <iostream>
#include <vector>
#include <random>

void fill_random_vec(std::vector<int> &v) {
  std::random_device rd; 
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 100);

  int n;
  for (int i = 0; i < 10; i++)
  {
    n = distrib(gen);
    v.push_back(n);
  }
}