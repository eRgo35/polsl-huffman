#include <iostream>
#include <queue>
#include <map>

#include "huffman.h"

bool is_leaf(huffman_node *node)
{
  return false;
}

void compress(huffman_node *tree, std::string &data, std::map<char, std::string> &result)
{
}

void decompress(huffman_node *tree, std::string &result)
{
}

void create_tree(std::string &data)
{
  if (data == "")
    return;

  std::map<char, int> frequency;
  for (char symbol : data)
    frequency[symbol]++;

  std::priority_queue<huffman_node*, std::vector<huffman_node*>> queue;

  for (std::pair<char, int> letter : frequency)
  {
    huffman_node *node = new huffman_node;
    
    node->symbol = letter.first;
    node->frequency = letter.second;
    node->left = nullptr;
    node->right = nullptr;
    
    queue.push(node);
  }
}
