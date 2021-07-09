#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <fstream>

class vertex;

class edge
{
public:
  vertex *v;
  int weight;

  edge(vertex* vt,int w)
  {
    v = vt; weight = w;
  }
};

class fhNode;

class vertex
{
public:
    char key;
    int d;
    vertex *p;
    fhNode* node;
    std::vector<edge> edges;
    
    vertex(char v) { key = v; d = 0; p = nullptr; node = nullptr; }
};

class graph
{
public:
  graph();
  ~graph();

  void dijkstra(char s);

  void pathTo(char dest,std::list<char>& L);
private:
  // Since the edges are stored in the vertices, we only need
  // a list of vertices in the graph.
  std::vector<vertex*> verts;
  // For convenience, we also set up a map that maps vertex labels
  // to vertices
  std::map<char,vertex*> V;
  int INF;
};
