#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <map>

bool check_arg(std::string &value, std::string arg);

bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary);

#endif