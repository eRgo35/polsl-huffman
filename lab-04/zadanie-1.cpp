#include <iostream>
#include <random>

int main()
{
  // source: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(1, 100);

  // utworzenie tablicy o wybranym rozmiarze
  const int N = {10};
  int tab[N];

  // wypełnianie wartościami losowymi
  for (int i = 0; i < N; i++)
    tab[i] = distrib(gen);

  // wypisanie tablicy
  for (int i = 0; i < N; i++)
    std::cout << tab[i] << ' ';
  std::cout << std::endl;

  // minimalny element tablicy
  int min = tab[0];
  int minI = 0;

  for (int i = 0; i < N; i++)
  {
    if (min > tab[i])
    {
      min = tab[i];
      minI = i;
    }
  }
  std::cout << "Wartość minimalna: " << min << std::endl;

  // zamiana minimalnego elementu z pierwszym
  int tmp = tab[0];
  tab[0] = min;
  tab[minI] = tmp;

  for (int i = 0; i < N; i++)
    std::cout << tab[i] << ' ';
  std::cout << std::endl;

  // sortowanie tablicy
  for (int i = 0; i < N; i++)
  {
    int min = tab[i];
    for (int j = i; j < N; j++)
    {

      if (min > tab[j])
      {
        min = tab[j];
        minI = j;
      }
    }
    int tmp = tab[i];
    tab[i] = min;
    tab[minI] = tmp;
  }

  for (int i = 0; i < N; i++)
    std::cout << tab[i] << ' ';
  std::cout << std::endl;

  return 0;
}