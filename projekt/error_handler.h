/**
 * @file error_handler.h
 * @brief Simple header that holds the general error handler for the program.
 * @author Michał Czyż
*/

#ifndef ERROR_H
#define ERROR_H

#include <iostream>

/// @brief Generates an error output in the console and help, with an instruction of how to use a program.
/// @param program_name A string that holds a name of a program to printout.
/// @param message A string containing an error message to printout.
/// @return Always returns false.
bool error_handler(std::string program_name, std::string message);

#endif