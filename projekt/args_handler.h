#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

/// @brief Function checks if the specified argument exists and is valid.
/// @param value 
/// @param arg 
/// @return 
bool check_arg(std::string &value, std::string arg);

bool push_into_error_buffer(std::vector<std::string> &target, std::string &error);

/// @brief Function handles all incoming arguments from argv array and sets all necessary options and paths into input, output, mode and dictionary variables. 
/// @param argc 
/// @param argv 
/// @param input 
/// @param output 
/// @param mode 
/// @param dictionary 
/// @return 
bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary);

#endif