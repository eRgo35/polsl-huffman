/**
 * @file error_handler.cpp
 * @brief Implements functions that are defined in error_handler.h
 * @author Michał Czyż
*/

#include <iostream>

#include "error_handler.h"

bool error_handler(std::string program_name, std::string message = "")
{
  std::cout << "Huffman tool 1.0.0 : Michał Czyż" << std::endl
            << std::endl;
  std::cout << message;
  std::cout << std::endl
            << "Usage: " << program_name << " -i <input_file> -o <output_file> -t <mode> -s <dictionary_file>" << std::endl;
  std::cout << std::endl
            << "Available parameters:" << std::endl
            << "-i <input_file> - path to the input file" << std::endl
            << "-o <output_file> - path to the output file" << std::endl
            << "-t <mode> - operation mode; k <- compression, d <- decompression" << std::endl
            << "-s <dictionary_path> - path to the dictionary file" << std::endl;
  return false;
}
