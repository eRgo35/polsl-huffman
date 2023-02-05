/** 
 * @file args_handler.h 
 * @brief Defines functions needed for parameters recognition and error handling.
 * @author Michał Czyż
*/

#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

/// @brief Checks if parameters exist. 
/// @param value Value of an arguement.
/// @param arg Passed argument.
/// @return Returns false if there is a problem i.e. arg is empty or there is no dash.
bool check_arg(std::string &value, std::string arg);

/// @brief Pushes errors into an error buffer so if more errors occure in one go the program will list them line-by-line.
/// @param target A reference to the target vector of string holding all errors.
/// @param error A reference to a string holding an error message.
/// @return Will always return false to signal that an error occured.
bool push_into_error_buffer(std::vector<std::string> &target, std::string &error);

/// @brief Handles the arguments passed to the program.
/// @param argc The number of arguments passed to the program.
/// @param argv An array of pointers to the arguments passed to the program.
/// @param input A reference to a string that will contain the file name of the input.
/// @param output A reference to a string that will contain the file name of the output.
/// @param mode A reference to a string that will contain program mode (compression/decompression).
/// @param dictionary A reference to a string that will contain the file name of the dictionary file.
/// @return Will return true if the arguemtns were successfully handled. Otherwise, it will return false.
bool arguments_handler(int argc, char *argv[], std::string &input, std::string &output, std::string &mode, std::string &dictionary);

#endif