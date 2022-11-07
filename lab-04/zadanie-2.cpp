#include <iostream>

int main()
{
  const int len{32};
  int dec = 0;
  int bin[len];

  std::cout << "Podaj liczbę którą chcesz przekonwertować: ";
  std::cin >> dec;

  for (int i = 0; i < len; i++)
  {
    if (dec % 2)
      bin[i] = 1;
    else
      bin[i] = 0;
    dec /= 2;
  }

  bool zeros = false;
  for (int i = len; i >= 0; i--)
  {
    if (bin[i] || zeros)
    {
      zeros = true;
      std::cout << bin[i];
    }
  }
  std::cout << std::endl;

  return 0;
}