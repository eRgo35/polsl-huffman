/** @file */
/* main.cpp
 */

#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "args_handler.h"
#include "file_handler.h"
#include "error_handler.h"
#include "huffman.h"

int main(int argc, char **argv)
{
  // params init
  std::string program_name = argv[0];
  std::string input_file = "";
  std::string output_file = "";
  std::string mode = "";
  std::string dictionary_file = "";
  std::string data = "";
  std::string dictionary = "";

  // arguments handler
  if (!arguments_handler(argc, argv, input_file, output_file, mode, dictionary_file))
    return 0;

  std::cout << "reading files..." << std::endl;

  // read file from arguments
  if (!read_file(program_name, data, input_file))
    return 0;

  // check if provided data is empty
  if (data == "")
  {
    error_handler(program_name, "File is empty");
    return 0;
  }

  // compression/decompression
  if (mode == "k")
  {
    // frequency tree is not sorted yet
    std::map<char, int> frequency;
    // the same frequency tree but characters are mapped to binary codes
    std::map<char, std::string> compressed_frequency;
    // compression result
    std::string compressed_data = "";

    std::cout << "creating binary tree..." << std::endl;

    for (char symbol : data)
      frequency[symbol]++;

    huffman_node *tree = create_tree(frequency);
    
    std::cout << "compressing..." << std::endl;
    
    // compress(tree, compressed_data, compressed_frequency);

    std::cout << "saving results..." << std::endl;

    // save result to a file
    if (!write_file(program_name, compressed_data, output_file, true))
      return 0;

    // save dictionary to a file
    if (!write_file(program_name, dictionary, dictionary_file, false))
      return 0;
    
    std::cout << "cleaning up..." << std::endl;

    clear_tree(tree);

    std::cout << "done." << std::endl;
  }
  else if (mode == "d")
  {
      // read dictionary file
      if (!read_file(program_name, dictionary, dictionary_file))
        return 0;
    // huffman_node *tree = rebuild_tree(dictionary);
    // decompress(tree, data);
  }
  else
  {
    error_handler(program_name, "Something went wrong. Try again.");
    return 0;
  }

  std::cout << "Operation completed successfully" << std::endl;

  return 0;
}