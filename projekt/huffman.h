/** @file */
/* huffman.h
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <map>
#include <string>

/// @brief Huffman node structure. It holds information about the letter, its frequency and the left and right child.
struct huffman_node
{
  char symbol;
  unsigned int frequency;
  huffman_node *left, *right;
};

/// @brief check if the provided huffman_node is a leaf: the node has no more children.
/// @param node 
/// @return 
bool is_leaf(huffman_node *node);

/// @brief Compress contents of a provided huffman_node into a string of ones and zeroes.
/// @param tree 
/// @param data 
/// @param result 
void compress(huffman_node *node, std::string data, std::map<char, std::string> &frequency);

/// @brief Decompresses contents of a provided huffman_node into an original string.
/// @param tree 
/// @param i 
/// @param res 
void decompress(std::map<std::string, char> &frequency, std::string &data, std::string &result);

/// @brief Generates a huffman tree structure.
/// @param data 
/// @return
huffman_node* create_tree(std::map<char, int> &frequency);

/// @brief Rebuilds huffman tree structure from a file
/// @param data 
/// @return 
std::map<std::string, char> rebuild_tree(std::string &dictionary);

void clear_tree(huffman_node *node);

char unescape_char(std::string character);

#endif