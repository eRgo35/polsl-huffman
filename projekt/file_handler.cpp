#include <iostream>
#include <map>
#include <sstream>
#include <sys/stat.h>
#include <algorithm>
#include <vector>

#include "file_handler.h"
#include "error_handler.h"

bool read_file(std::string program_name, std::string &data, std::string &file_name)
{
  std::ifstream file(file_name);
  std::string line;

  if (!file.good())
  {
    return error_handler(program_name, "Input file is invalid");
  }

  std::map<char, int> frequency;
  std::stringstream buffer;
  buffer << file.rdbuf(); 
  std::string file_content = buffer.str();

  for (std::size_t i = 0; i < file_content.size(); i++)
  {
    frequency[file_content[i]]++;
  }

  for (const auto &c : frequency)
  {
    std::cout << c.first << " | " << c.second << std::endl;
  }

  return true;
}