#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>

struct huffman_tree {
  unsigned long int size;
  unsigned long int total_size;
  struct huffman_tree_node** array;
};

struct huffman_tree_node {
  char input_char;
  unsigned long int frequency;
  struct huffman_tree_node *left;
  struct huffman_tree_node *right;
};

bool encrypt(std::string &input, std::string &output, std::string &dictionary);

bool decrypt(std::string &input, std::string &output, std::string &dictionary);

#endif