/**
 * @file huffman.cpp
 * @brief Implements functions defined in huffman.h, contains the core functionality of this program.
 * @author Michał Czyż
*/

#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <vector>
#include <string>

#include "huffman.h"

// custom sorter for the priority queue, so the frequencies get pulled out by the lowest frequency number.
auto lowest_frequency = [](huffman_node *left, huffman_node *right)
{
  return left->frequency > right->frequency;
};

// basic leaf check, if node has no children, it's a leaf node.
bool is_leaf(huffman_node *node)
{
  if (node->left == nullptr && node->right == nullptr)
    return true;
  return false;
}

void compress(huffman_node *node, std::string data, std::map<char, std::string> &frequency)
{ 
  // check if node exists
  if (node == nullptr)
    return;

  // check if node is the last element (leaf) in a tree
  if (is_leaf(node))
  {
    frequency[node->symbol] = (data != "") ? data : "1";
  }

  compress(node->left, data + "0", frequency);
  compress(node->right, data + "1", frequency);
}

void decompress(std::map<std::string, char> &frequency, std::string &data, std::string &result)
{
  std::string code;
  for (char c : data)
  {
    // add charcters as to a string as long as some code get found in a dictionary map
    code += c;
    if (frequency.count(code) > 0)
    {
      // adds the value of the code into the result and resets itself
      result += frequency[code];
      code = "";
    }
  }
}

huffman_node* create_tree(std::map<char, int> &frequency)
{
  // unfortunately priority_queue is not as easy at it seems... Documentation said that using operator() function is not recommended
  std::priority_queue<huffman_node*, std::vector<huffman_node*>, decltype(lowest_frequency)> queue(lowest_frequency);

  // create nodes out of symbol map
  for (std::pair<char, int> letter : frequency)
  {
    huffman_node *node = new huffman_node;
    
    node->symbol = letter.first;
    node->frequency = letter.second;
    node->left = nullptr; // no children - it's a leaf node
    node->right = nullptr; // -||-

    queue.push(node);
  }

  while (queue.size() > 1)
  {
    huffman_node* left = queue.top();
    queue.pop();
    huffman_node* right = queue.top();
    queue.pop();

    // creating internal node from two leaf nodes
    huffman_node* node = new huffman_node;

    node->symbol = '\0'; // null char
    node->frequency = left->frequency + right->frequency; // sum of previous frequencies
    node->left = left;
    node->right = right;

    queue.push(node);
  }

  // return last object left in the queue (the entire tree)
  return queue.top();
}

std::map<std::string, char> rebuild_tree(std::string &dictionary)
{
  std::map<std::string, char> dictionary_map;
  std::stringstream dictionary_stream(dictionary);
  std::string ch;
  std::string code; 

  while (true)
  {
    std::getline(dictionary_stream, ch);
    if(!std::getline(dictionary_stream, code))
      break;

    char c = unescape_char(ch);

    dictionary_map[code] = c;
  }

  return dictionary_map;
}

void clear_tree(huffman_node *node)
{
  // check if node exists
  if (node == nullptr)
    return;
  
  // recursively traverse the node
  clear_tree(node->left);
  clear_tree(node->right);

  // remove node from the heap
  delete node;
}

std::string escape_char(char character)
{
  if (character == '\n')
    return "'\\n'";
  return std::string(1, character);
}

char unescape_char(std::string character)
{
  if (character == "'\\n'")
    return '\n';
  return character.c_str()[0];
}