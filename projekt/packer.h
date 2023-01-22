#ifndef PACKER_H
#define PACKER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

struct huffman_node {
  std::string symbol;
  unsigned int frequency;
  struct huffman_node *left, *right;
};

bool compress(std::string &input, std::string &output, std::string &dictionary);

bool decompress(std::string &input, std::string &output, std::string &dictionary);

#endif