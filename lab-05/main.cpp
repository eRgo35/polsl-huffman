#include <vector>
#include <iostream>
#include "defs.h"

int main()
{
  double n3 = 3.14;
  int a4 = 1;
  int b4 = 2;
  const int arrl = 10;
  int arr[arrl] = {3, 1, 4, 1, 5, 9, 2, 6, 2, 9};
  int n7;
  std::vector<int> vec;
  std::vector<int> vec8;

  std::cout << "1. " << fun(4, 5) << std::endl;
  std::cout << "2. " << max(2.1, 5.3, 6.44) << std::endl;
  dodaj3(n3);
  std::cout << "3. " << n3 << std::endl;
  my_swap(a4, b4);
  std::cout << "4. " << a4 << " -> " << b4 << std::endl;

  std::cout << arr << std::endl;
  std::cout << arr + 1 << std::endl;

  print_tab(arr, arrl);
  
  sort_tab(arr, arrl);

  for (int n : arr)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  n7 = is_prime(13);

  std::cout << (n7 ? "true" : "false") << std::endl;
  
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(7);

  print_vec(vec);

  fill_random_vec(vec8);

  for (int a : vec8) {
    std::cout << a << " ";
  }
  std::cout << std::endl;

  return 0;
}