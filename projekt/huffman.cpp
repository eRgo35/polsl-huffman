#include <iostream>
#include <queue>
#include <map>

#include "huffman.h"

auto lowest_frequency = [](huffman_node *left, huffman_node *right)
{
  return left->frequency > right->frequency;
};

bool is_leaf(huffman_node *node)
{
  return false;
}

void compress(huffman_node *node, std::string data, std::map<char, std::string> &frequency)
{ 
  std::string binary_number;
  
  // check if node exists
  if (node == nullptr)
    return;

  // check if node is the last element (leaf) in a tree
  if (is_leaf(node))
  {
    
    frequency[node->symbol] = binary_number;
  }

  compress(node->left, data + "0", frequency);
  compress(node->right, data + "1", frequency);
}

void decompress(huffman_node *tree, std::string &result)
{
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

// huffman_node* rebuild_tree(std::string &dictionary)
// {
  


// }


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