#include <iostream>
#include <iomanip>

int main()
{
  int W = {0x10};
  int K = {0x10};

  std::cout << "   |";

  for (int w = 1; w <= W; w++)
  {
    std::cout << std::setw(3) << std::hex << w << ' ';
  }
  std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

  for (int w = 1; w <= W; w++)
  {
    std::cout << std::setw(3) << std::hex << w << "|";
    for (int k = 1; k <= K; k++)
    {
      std::cout << std::hex << std::setw(3) << w * k << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}