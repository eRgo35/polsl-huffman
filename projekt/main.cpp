#include <iostream>

#include "args_handler.h"
#include "file_handler.h"
#include "packer.h"

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

  if (!build_tree(input))
    return 0;

  // encryption/decryption
  bool status = false;
  
  if (mode == "k")
    status = compress(input, output, dictionary);  
  else if (mode == "d")
    status = decompress(input, output, dictionary);
  else
    return 0;
  
  // results
  if (status)
    std::cout << "Operation completed successfully!" << std::endl;
  else
   std::cout << "Error encountered" << std::endl;

  return 0;
}