#include <iostream>

#include "args_handler.h"
#include "file_handler.h"

int main(int argc, char **argv)
{
  // params init
  std::string input, output, mode, dictionary;
  std::string data;
  std::string name = argv[0];

  // argument check
  if (!arguments_handler(argc, argv, input, output, mode, dictionary))
    return 0;

  // read file from arguments
  if (!read_file(name, data, input))
    return 0;

  return 0;
}