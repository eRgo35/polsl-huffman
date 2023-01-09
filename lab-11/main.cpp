#include <iostream>
#include <vector>
#include <queue>

struct graph_node
{
  char value;
  std::vector<graph_node> neighbours;
};

struct graph
{
  unsigned int size;
  std::vector<graph_node> corners;
};

void DFS_util(graph_node node)
{
  std::cout << node.value << " ";
  for (graph_node next_node : node.neighbours)
  {
    DFS_util(next_node);
  }
}

void DFS(graph graph)
{
  std::vector<bool> visited(graph.corners.size(), false);
  std::queue<int> queue;

  for (int v = 0; v < graph.corners.size(); v++)
  {
    if (visited[v] == false)
    {
      visited[v] = true;
      queue.push(v);

      while (!queue.empty())
      {
        graph_node x = graph.corners[queue.front()];
        queue.pop();
        DFS_util(x);
      }
    }
  }
}

void BFS(graph graph)
{
  std::vector<bool> visited(graph.corners.size(), false);
  std::queue<int> queue;

  for (int v = 0; v < graph.corners.size(); v++)
  {
    if (visited[v] == false)
    {
      visited[v] = true;
      queue.push(v);

      while (!queue.empty())
      {
        graph_node x = graph.corners[queue.front()];
        queue.pop();
        std::cout << x.value << " ";
        for (auto y : x.neighbours)
        {
          std::cout << y.value << " ";
        }
      }
    }
  }
}

int main()
{
  graph Graph = {8, {{'A', {{'B', {{'D'}, {'E', {{'G'}, {'H'}}}}}, {'C', {{'F'}}}}}}};

  DFS(Graph);

  std::cout << std::endl;

  BFS(Graph);

  std::cout << std::endl;

  return 0;
}