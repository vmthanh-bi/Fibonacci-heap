#include "graph.h"
#include <iostream>

int main() {
  graph G;
  // Starting from vertex a
  char start = 'a';
  std::cout << "Starting from vertex " << start << std::endl;
  // Find the shortest path to vertex t
  char dest = 't';
  std::cout << "Going to vertex " << dest << std::endl;

  // Run the Dijkstra algorithm
  G.dijkstra(start);

  std::list<char> L;
  G.pathTo(dest,L);

  std::list<char>::iterator itr = L.begin();
  std::cout << *itr;
  itr++;
  while(itr != L.end()) {
    std::cout << "," << *itr;
    itr++;
  }
  std::cout << std::endl;
}
