/**
 * @file file_handler.cpp
 * @brief Implements functions for interaction with the filesystem defined in file_handler.h.
 * @author Michał Czyż
*/

#include <iostream>
#include <map>
#include <sstream>
#include <sys/stat.h>
#include <algorithm>

#include "file_handler.h"
#include "error_handler.h"

// size of a ascii chunk (saving binary ones and zeroes to ascii)
const int chunk_size = 8;

bool read_file(std::string program_name, std::string &data, std::string &file_name, bool binary)
{ 
  if (binary)
  {
    std::ifstream file(file_name, std::ios::in | std::ios::binary);

    if (!file.good())
      return error_handler(program_name, "Output file is invalid");

    char byte;

    // reads a byte from a file in a loop
    // then it checks if the consecutive bits are 0 or 1
    // if AND succeds consecutive numbers are added into a data string
    while (file.read(&byte, 1))
      for (int i = chunk_size - 1; i >= 0; i--)
        data += (byte & (1 << i)) ? '1' : '0';
        
    return true;
  }

  std::ifstream file(file_name);
  std::string line;

  if (!file.good())
    return error_handler(program_name, "Input file is invalid");

  // reads a file buffer into a stringstream and then, it's stringified
  // this allows to read even binary files because they just get translated into unicode characters
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

    char byte = 0;
    int count = 0;

    for (char c : data)
    { 
      // byte is shifted left by 1, and then OR writes a new bit based on the incoming string.
      byte = (byte << 1) | (c == '1' ? 1 : 0);
      count++;
      
      // if byte is finally 8 bits long it is being put into a file and reset back to zero.
      if (count == chunk_size)
      {
        file.put(byte);
        byte = 0;
        count = 0;
      }
    }

    // if there are any lefrover bytes, they get additional zeros to the end
    // and pushed into the file.
    if (count > 0)
    {
      byte <<= (chunk_size - count);
      file.put(byte);
    }

    return true;
  }

  std::ofstream file(file_name);

  if (!file.good())
    return error_handler(program_name, "Output file is invalid");
  
  // just standard data writing into a file
  file << data;

  return true;
}