#include <iostream>
#include <iomanip>

int main()
{
  const int W = {6};
  const int K = {6};

  int arr[W][K];

  int n = 1;
  for (int i = 0; i < W; i++)
    arr[0][i] = n++;
  for (int i = 1; i < K; i++)
    arr[i][K - 1] = n++;
  n = 16;
  for (int i = 1; i < W; i++)
    arr[W - 1][i - 1] = n--;
  n = 20;
  for (int i = 1; i < K; i++)
    arr[i][0] = n--;

  n = 20;
  for (int i = 0; i < (W - 1); i++)
    arr[1][i] = n++;
  for (int i = 1; i < (K - 2); i++)
    arr[i + 1][K - 2] = n++;
  n = 30;
  for (int i = 1; i < (W - 2); i++)
    arr[W - 2][i] = n--;
  n = 32;
  for (int i = 1; i < (K - 3); i++)
    arr[i + 1][1] = n--;

  n = 33;
  for (int i = 0; i < (W - 4); i++)
    arr[2][i + 2] = n++;

  n = 36;
  for (int i = 0; i < (W - 4); i++)
    arr[3][i + 2] = n--;

  for (int w = 0; w < W; w++)
  {
    for (int k = 0; k < K; k++)
      std::cout << std::setw(2) << arr[w][k] << ' ';
    std::cout << std::endl;
  }

  return 0;
}