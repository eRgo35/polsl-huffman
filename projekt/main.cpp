#include <iostream>
#include <string>

#include <fstream>

#include "args_handler.h"
#include "file_handler.h"
#include "huffman.h"

int main(int argc, char **argv)
{
  // params init
  std::string input_file, output_file, mode, dictionary_file;
  std::string program_name = argv[0];
  std::string data;

  // arguments handler
  if (!arguments_handler(argc, argv, input_file, output_file, mode, dictionary_file))
    return 0;

  // read file from arguments
  if (!read_file(program_name, data, input_file))
    return 0;

  // compression/decompression
  bool status = false;
  
  std::string dictionary; // that one will load from a file

  // if (mode == "k")
  // {
  // }  
  // else if (mode == "d")
  // {
  // }  
  // else
  //   return 0;
  
  create_tree(data);

  std::cout << data << std::endl;

  // std::ofstream file(output_file);
  // if (file)
  // {
  //   file.write((char *)&data, sizeof(std::string));
  // }

  // save result to a file
  // if (!write_file(program_name, data, output_file));
  //   return 0;

  // // save dictionary to a file
  // if (!write_file(program_name, dictionary, dictionary_file));
  //   return 0;

  // // debug response results
  // if (status)
  //   std::cout << "Operation completed successfully!" << std::endl;
  // else
  //  std::cout << "An error occurred!" << std::endl;

  return 0;
}