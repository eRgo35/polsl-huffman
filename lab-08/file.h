#ifndef FILE_H
#define FILE_H

#include <iostream>

void num_gen(const std::string &out_name, int n);

unsigned long long get_file_size(const std::string &file_name);

void calculate_statistics(const std::string &intput_file_name, const std::string &output_file_name_txt, const std::string &output_file_name_bin);

void youngest_oldest(const std::string &file_name);

void copy_text(const std::string& input_file_name, const std::string& output_file_name);

void copy_binary(const std::string& input_file_name, const std::string& output_file_name);

#endif