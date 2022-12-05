#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <ios>

#include "file.h"

std::default_random_engine engine;
std::uniform_int_distribution<int> distrib(0, 9999);

void num_gen(const std::string &out_name, int n)
{
  std::ofstream file(out_name);
  if (!file)
  {
    std::cerr << "Wystąpił błąd przy zapisie do pliku";
    exit(0);
  }

  for (size_t i = 0; i < n; i++)
    file << distrib(engine) << std::endl;
}

unsigned long long get_file_size(const std::string &file_name)
{
  std::ifstream file(file_name, std::ifstream::ate | std::ifstream::binary);
  return file.tellg();
}

void calculate_statistics(const std::string &intput_file_name, const std::string &output_file_name_txt, const std::string &output_file_name_bin)
{
  std::ifstream file(intput_file_name);
  std::vector<int> nums;
  int num;

  if (!file)
  {
    std::cerr << "Wystąpił błąd przy odczycie z pliku";
    exit(0);
  }

  while (file >> num)
    nums.push_back(num);

  int sum = 0;
  for (int nm : nums)
    sum += nm;

  double avg = sum / nums.size();

  int max = nums[0];
  for (size_t i = 1; i < nums.size(); i++)
    if (nums[i] > max)
      max = nums[i];

  std::ofstream out(output_file_name_txt, std::ios::app);
  if (!out)
  {
    std::cerr << "Wystąpił błąd przy zapisie do pliku";
    exit(0);
  }

  out << "avg: " << avg << ", max: " << max << std::endl;

  std::ofstream outb(output_file_name_bin, std::ios::app);
  if (!outb)
  {
    std::cerr << "Wystąpił błąd przy zapisie do pliku";
    exit(0);
  }

  struct
  {
    double avg;
    int max;
  } avg_max{avg, max};

  outb.write((char *)&avg_max, sizeof(int));
}

void youngest_oldest(const std::string &file_name)
{
  std::ifstream file(file_name);
  if (!file)
  {
    std::cerr << "Wystąpił błąd przy odczycie z pliku";
    exit(0);
  }

  std::string name;
  int age;

  struct person
  {
    std::string name;
    int age;
  };

  std::vector<person> people;

  while (file >> name >> age)
    people.push_back({name, age});
  
  

  std::cout << "youngest: "
            << "oldest: ";
}

void copy_text(const std::string &input_file_name, const std::string &output_file_name)
{
}

void copy_binary(const std::string &input_file_name, const std::string &output_file_name)
{
}