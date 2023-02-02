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
    return error_handler(program_name, "Input file is invalid");

  std::stringstream buffer;
  buffer << file.rdbuf();
  data = buffer.str();

  return true;
}

bool write_file(std::string program_name, std::string &data, std::string &file_name, bool binary)
{  
  if (binary)
  {
    std::ofstream file(file_name, std::ios::binary);

    if (!file.good())
      return error_handler(program_name, "Output file is invalid");

    file.write((char *)data.c_str(), sizeof(std::string));

    return true;
  }

  std::ofstream file(file_name);

  if (!file.good())
    return error_handler(program_name, "Output file is invalid");

  file << data;

  return true;
}