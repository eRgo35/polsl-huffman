#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <string>

struct graph_node
{
  char value;
  int distance;
  std::vector<graph_node> neighbours;
};

struct graph
{
  unsigned int size;
  std::vector<graph_node> corners;
};

void find_path(graph &graph, char &source, char &destination)
{
  std::vector<char> result = "";
  std::map<char, int> distance_table;
  
  for (auto corner : graph.corners)
  {
    if (corner == source)
    {
      result.push(source);
      // distance_table.push({corner, 0});
    }
  }

}

int main()
{
  graph star = {5, {
      {'A', 0, {
        {'B', 10}, 
        {'C', 80}, 
        {'D', 60}, 
        {'E', 40}
      }}, 
      {'B', 0, {
        {'D', 10},
        {'E', 5}
      }}, 
      {'C', 0, {
        {'B', 10}
      }}, 
      {'D', 0, {
        {'C', 30}
      }}, 
      {'E', 0, {
        {'C', 20},
        {'D', 60}
      }}
    }};

  char source = 'A';
  char destination = 'C';

  find_path(star, source, destination);

  std::cout << std::endl;

  return 0;
}