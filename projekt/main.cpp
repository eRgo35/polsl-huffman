/**
 * @file main.cpp
 * @brief Main program file.
 * @author Michał Czyż
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#include "args_handler.h"
#include "file_handler.h"
#include "error_handler.h"
#include "huffman.h"

int main(int argc, char **argv)
{
  // params init
  std::string program_name = argv[0];
  std::string input_file, output_file, mode, dictionary_file, data = "";

  // arguments handler
  if (!arguments_handler(argc, argv, input_file, output_file, mode, dictionary_file))
    return 0;

  // compression/decompression
  if (mode == "k")
  {
    std::cout << "reading file..." << std::endl;

    // read file from arguments
    if (!read_file(program_name, data, input_file, false))
      return 0;

    // check if provided data is empty
    if (data == "")
    {
      error_handler(program_name, "File is empty");
      return 0;
    }

    // frequency tree is not sorted yet
    std::map<char, int> frequency;
    // the same frequency tree but characters are mapped to binary codes
    std::map<char, std::string> compressed_frequency;

    std::string compressed_data = "";

    std::cout << "creating binary tree..." << std::endl;

    // adding chars to a map and counting its frequency
    for (char symbol : data)
      frequency[symbol]++;

    // creation of the tree structure
    huffman_node *tree = create_tree(frequency);
  
    std::cout << "compressing..." << std::endl;

    // recursive merge of a tree into huffman binary codes 
    compress(tree, "", compressed_frequency);

    // translating letters into codes
    for (auto c : data)
      compressed_data += compressed_frequency[c];

    // entire frequency map gets converted into a stringstream
    // so it can be saved into a file
    std::stringstream dictionary;

    for (auto a : compressed_frequency)
    {
      std::string key = escape_char(a.first); 
      dictionary << key << std::endl << a.second << std::endl;
    }

    // stringifing a stream
    std::string dictionary_str = dictionary.str();

    std::cout << "saving results..." << std::endl;

    // save result to a file
    if (!write_file(program_name, compressed_data, output_file, true))
      return 0;

    // save dictionary to a file
    if (!write_file(program_name, dictionary_str, dictionary_file, false))
      return 0;

    std::cout << "cleaning up..." << std::endl;

    // cleaning heap from the original tree struct
    clear_tree(tree);

    std::cout << "done." << std::endl;
  }
  else if (mode == "d")
  {
    std::string dictionary_raw = "";
    std::string decompressed_data = "";

    std::cout << "reading files..." << std::endl;

    // read file from arguments
    if (!read_file(program_name, data, input_file, true))
      return 0;
    
    // read dictionary from arguments
    if (!read_file(program_name, dictionary_raw, dictionary_file, false))
      return 0;

    // checking if data and dictionary are not empty
    if (data == "")
    {
      error_handler(program_name, "File is empty");
      return 0;
    }

    if (dictionary_raw == "")
    {
      error_handler(program_name, "Dictionary is empty");
      return 0;
    }

    std::cout << "rebuilding binary tree..." << std::endl;

    // rebuilding a frequency map from a file
    std::map<std::string, char> frequency = rebuild_tree(dictionary_raw);
  
    std::cout << "decompressing..." << std::endl;

    // decompression by comparison
    decompress(frequency, data, decompressed_data);

    std::cout << "saving results..." << std::endl;

    // save result to a file
    if (!write_file(program_name, decompressed_data, output_file, false))
      return 0;

    std::cout << "done." << std::endl;
  }
  else
  {
    error_handler(program_name, "Something went wrong. Try again.");
    return 0;
  }

  std::cout << "Operation completed successfully!" << std::endl;

  return 0;
}