/** @file */
/* file_handler.h
 */

#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <iostream>
#include <fstream>

/// @brief Function opens a file, reads its contents and stores it inside data variable.
/// @param program_name 
/// @param data 
/// @param file_name 
/// @return 
bool read_file(std::string program_name, std::string &data, std::string &file_name);

/// @brief Function opens a file, writes results into it.
/// @param program_name 
/// @param data 
/// @param file_name 
/// @return 
bool write_file(std::string program_name, std::string &data, std::string &file_name, bool binary);

#endif