/**
 * @file file_handler.h
 * @brief Defines functions for interaction with the filesystem.
 * @author Michał Czyż
*/

#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <iostream>
#include <fstream>

/// @brief Reads data from the provided file.
/// @param program_name A string containing the program_name which in case of an error is passed down to the error_handler.
/// @param data A reference to a string that will hold the data read from the file.
/// @param file_name A reference to a string that holds the file name of a desired file.
/// @param binary A method in which the function should read the file (true for binary or false for normal filestream).
/// @return Returns true if operation completed successfully, false if it failed.
bool read_file(std::string program_name, std::string &data, std::string &file_name, bool binary);

/// @brief Writed data to the provided file.
/// @param program_name A string containing the program_name which in case of an error is passed down to the error_handler.
/// @param data A reference to a string that holds the data.
/// @param file_name A reference to a string that holds the file name of a desired file.
/// @param binary A method in which the function should write into the file (true for binary or false for normal filestream).
/// @return Returns true if operation completed successfully, false if it failed.
bool write_file(std::string program_name, std::string &data, std::string &file_name, bool binary);

#endif