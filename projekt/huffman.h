/**
 * @file huffman.h
 * @brief Defines core functions of the program.
 * @author Michał Czyż 
*/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <map>
#include <string>

/**
 * @struct huffman_node
 * @brief huffman node structure used later to create a tree of frequencies.
*/
struct huffman_node
{
  char symbol; /**< The symbol, letter that's stored in a node, later it's just a null character */
  unsigned int frequency; /**< The frequency of that letter it has been apearing in data */
  huffman_node *left, *right; /**< Pointers to the left (1) and right (0) child of a node. */
};

/// @brief Checks if the provided node has no children. It it the leaf of a tree.
/// @param node A pointer to the node that has to be checked.
/// @return Returns true if the node is a leaf node.
bool is_leaf(huffman_node *node);

/// @brief Compresses data recursively to a binary stream.
/// @param node A pointer to the huffman tree root.
/// @param data A string of data to be compressed.
/// @param frequency A reference to a frequency map.
void compress(huffman_node *node, std::string data, std::map<char, std::string> &frequency);

/// @brief Decompresses binary stream back to the normal format.
/// @param frequency A reference to an inverted frequency map.
/// @param data A reference to the string of encoded data.
/// @param result A reference to the string that will contain decomressed data.
void decompress(std::map<std::string, char> &frequency, std::string &data, std::string &result);

/// @brief Creates a huffman binary tree out of a map of frequencies.
/// @param frequency A reference to a map of frequencies.
/// @return Returns a pointer to a huffman binary tree.
huffman_node* create_tree(std::map<char, int> &frequency);

/// @brief Rebuilds an inverted (easier to process later) frequency map from a string. 
/// @param dictionary A reference to a string that holds a map.
/// @return Returns an inverted frequency map.
std::map<std::string, char> rebuild_tree(std::string &dictionary);

/// @brief Clears a heap of a huffman tree so the program doesn't leak any data.
/// @param node A pointer to a node that has to be cleared. By default it should be the entire tree.
void clear_tree(huffman_node *node);

/// @brief Escapes difficult character that might break something later
/// @param character A char that holds a normal character to escape i.e '\\n'.
/// @return Returns an escaped version of a character.
std::string escape_char(char character);

/// @brief Unescapes characters and prints them in a normal form.
/// @param character A string holding an encoded character to escape i.e '\\n'.
/// @return Returns a raw, unescaped character.
char unescape_char(std::string character);

#endif