#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> error_messages{
    {"not_enough", "Too few arguments.\n"},
    {"input", "-i argument requires <input_file> path.\n"},
    {"output", "-o argument requires <output_file> path.\n"},
    {"mode", "-t argument requires <mode>; k <- compression, d <- decompression.\n"},
    {"dictionary", "-s argument requires <dictionary_file> path.\n"},
};

bool check_arg(std::string &value, std::string arg)
{
  if (arg == "" || arg.find("-") != std::string::npos)
    return false;

  value = arg;
  return true;
}

bool error_handler(std::string name, std::string message = "")
{
  std::cout << "Huffman compression/decompression tool 1.0.0 : Copyright (c) 2022 Michał Czyż" << std::endl
            << std::endl;
  std::cout << message;
  std::cout << std::endl
            << "Usage: " << name << " -i <input_file> -o <output_file> -t <mode> -s [dictionary_file]" << std::endl;
  std::cout << std::endl
            << "Available parameters:" << std::endl
            << "-i <input_file> - path to the input file" << std::endl
            << "-o <output_file> - path to the output file" << std::endl
            << "-t <mode> - operation mode; k <- compression, d <- decompression" << std::endl
            << "-s <dictionary_path> - path to the dictionary file" << std::endl;
  return false;
}

bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary)
{
  bool in, out, md, dc = true;

  if (argc < 7)
    return error_handler(argv[0], error_messages["not_enough"]);

  for (int i = 1; i < argc; i++)
  {
    std::string args = std::string(argv[i]);

    if (args == "-i")
      in = !check_arg(input, argv[i + 1]) ? error_handler(argv[0], error_messages["input"]) : true;

    if (args == "-o")
      out = !check_arg(output, argv[i + 1]) ? error_handler(argv[0], error_messages["output"]) : true;

    if (args == "-t")
      md = !check_arg(mode, argv[i + 1]) ? error_handler(argv[0], error_messages["mode"]) : true;

    if (args == "-s")
      dc = !check_arg(dictionary, argv[i + 1]) ? error_handler(argv[0], error_messages["dictionary"]) : true;

    if (!(in || out || md || dc))
      return false;
  }

  // check if params exist
  // in = !check_arg(input, input) ? error_handler(argv[0], error_messages["input"]) : true;

  return true;
}

int main(int argc, char **argv)
{
  // params init
  std::string input, output, mode, dictionary;

  // argument read check
  if (!arguments_handler(argc, argv, input, output, mode, dictionary))
    return 0;

  std::cout << "Aye!" << std::endl;

  return 0;
}