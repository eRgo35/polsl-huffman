#include <iostream>
#include <string>
#include "defs.h"



int arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary)
{
  if (argc < 7)
  {
    return error_handler(argv[0]);
  }

  for (int i = 1; i < argc; i++)
  {
    if (std::string(argv[i]) == "-i" || std::string(argv[i]) == "--input")
    {
      if (i + 1 < argc)
        input = argv[i++];
      else
      {
        return error_handler(argv[0], "-i argument requires <input_file> path.");
      }
    }
    else if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--output")
    {
      if (i + 1 < argc)
        input = argv[i++];
      else
      {
        return error_handler(argv[0], "-o argument requires <output_file> path.");
      }
    }
    else if (std::string(argv[i]) == "-t" || std::string(argv[i]) == "--mode")
    {
      if (i + 1 < argc)
        input = argv[i++];
      else
      {
        return error_handler(argv[0], "-t argument requires <mode>; k <- compression, d <- decompression");
      }
    }
    else if (std::string(argv[i]) == "-s" || std::string(argv[i]) == "--dictionary")
    {
      if (i + 1 < argc)
        input = argv[i++];
      else
      {
        return error_handler(argv[0], "-s argument requires <dictionary_file> path");
      }
    }
    else if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help")
    {
      return error_handler(argv[0], "\nAvailable parameters:\n-i <input_file> - path to the input file\n-o <output_file> - path to the output file\n-t <mode> - operation mode; k <- compression, d <- decompression\n-s <dictionary_path> - path to the dictionary file");
    }
    else if (std::string(argv[i]) == "-v" || std::string(argv[i]) == "--version")
    {
      return error_handler(argv[0], "Huffman compression/decompression tool 1.0.0 : Copyright (c) 2022 Michał Czyż");
    }
    else
      std::cout << argv[i] << "\n";
  }
}