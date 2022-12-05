#include <iostream>
#include "file.h"

int main()
{
  num_gen("nums.txt", 10);

  unsigned long long size = get_file_size("main.dev");
  std::cout << "Size: " << size << " bytes" << std::endl;

  calculate_statistics("nums.txt", "nums_avg.txt", "nums_avg.bin");

  youngest_oldest("osoby.txt");

  return 0;
}