#include <iostream>
#include <map>

#include "args_handler.h"
#include "error_handler.h"

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

bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary)
{
  bool in, out, md, dc = true;

  if (argc < 7)
    return error_handler(argv[0], error_messages["not_enough"]);

  for (int i = 1; i < argc; i++)
  {
    std::string args = std::string(argv[i]);

    if (i + 1 >= argc)
      continue;

    if (args == "-i")
      in = !check_arg(input, argv[i + 1]) ? error_handler(argv[0], error_messages["input"]) : true;

    if (args == "-o")
      out = !check_arg(output, argv[i + 1]) ? error_handler(argv[0], error_messages["output"]) : true;

    if (args == "-t")
      md = !check_arg(mode, argv[i + 1]) ? error_handler(argv[0], error_messages["mode"]) : true;

    if (md && args == "-s")
      dc = !check_arg(dictionary, argv[i + 1]) ? error_handler(argv[0], error_messages["dictionary"]) : true;

    if (!(in || out || md))
      return false;
  }

  // check if params exist
  in = !check_arg(input, input) ? error_handler(argv[0], error_messages["input"]) : true;
  out = !check_arg(output, output) ? error_handler(argv[0], error_messages["output"]) : true;
  md = !check_arg(mode, mode) ? error_handler(argv[0], error_messages["mode"]) : true;
  // dc = !check_arg(dictionary, dictionary) ? error_handler(argv[0], error_messages["dictionary"]) : true;

  // TODO implement error info buffer

  if (!(in && out && md))
    return false;

  return true;
}