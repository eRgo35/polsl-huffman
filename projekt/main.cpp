#include <iostream>

#include "args_handler.h"
#include "file_handler.h"

int main(int argc, char **argv)
{
  // params init
  std::string input, output, mode, dictionary;
  std::string data;

  // argument read check
  if (!arguments_handler(argc, argv, input, output, mode, dictionary))
    return 0;

  // read file from arguments
  if (!read_file(data, input))
    return 0;

  return 0;
}