#include <iostream>
#include <sys/stat.h>

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

  while(std::getline(file, line));

  return true;
}