#include <iostream>
#include <sys/stat.h>

#include "file_handler.h"

bool err() {
  std::cout << "error";
  return false;
}

bool read_file(std::string &data, std::string &file_name)
{
  try
  {
    std::ifstream file(file_name);
    if (!file.good())
      return err();
    while(file >> data)
      std::cout << data;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return false;
  }

  return true;
}