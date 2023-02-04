#include <iostream>
#include <map>
#include <sstream>
#include <sys/stat.h>
#include <algorithm>
#include <vector>

#include "file_handler.h"
#include "error_handler.h"

// size of a chunk (saving binary ones and zeroes to ascii)
const int chunk_size = 8;

bool read_file(std::string program_name, std::string &data, std::string &file_name, bool binary)
{
  if (binary)
  {
    std::ifstream file(file_name, std::ios::in | std::ios::binary);

    if (!file.good())
      return error_handler(program_name, "Output file is invalid");

    char packed;

    while (file.read(&packed, 1))
      for (int i = chunk_size - 1; i >= 0; i--)
        data += (packed & (1 << i)) ? '1' : '0';
        
    return true;
  }

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
    std::ofstream file(file_name, std::ios::out | std::ios::binary);

    if (!file.good())
      return error_handler(program_name, "Output file is invalid");

    char packed = 0;
    int count = 0;

    for (char c : data)
    {
      packed = (packed << 1) | (c == '1' ? 1 : 0);
      count++;

      if (count == chunk_size)
      {
        file.put(packed);
        packed = 0;
        count = 0;
      }
    }

    if (count > 0)
    {
      packed <<= (chunk_size - count);
      file.put(packed);
    }

    return true;
  }

  std::ofstream file(file_name);

  if (!file.good())
    return error_handler(program_name, "Output file is invalid");

  file << data;

  return true;
}