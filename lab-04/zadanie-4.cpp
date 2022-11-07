#include <iostream>
#include <iomanip>

int main()
{
  int W = {6};
  int K = {6};

  int a = 1;
  for (int i = 0; i < W; i++)
  {
    for (int j = 0; j < K; j++)
    {
      std::cout << std::setw(2) << a << ' ';
      a++;
    }
    std::cout << std::endl;
  }

  return 0;
}