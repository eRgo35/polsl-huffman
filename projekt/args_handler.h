#ifndef ARGS_HANDLER
#define ARGS_HANDLER

#include <iostream>
#include <map>

bool check_arg(std::string &value, std::string arg);

bool error_handler(std::string name, std::string message);

bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary);

#endif