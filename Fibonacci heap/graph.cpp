#include "graph.h"
#include "fHeap.h"

graph::graph()
{
    INF = 100000;
    std::ifstream in;
    in.open("vertices.txt");
    
    char key;
    while (in >> key) {
        vertex* newVert = new vertex(key);
        V[key] = newVert;
        verts.push_back(newVert);
    }
    in.close();
    
    in.open("edges.txt");
    char start, end;
    int dist;
    while(in >> start >> end >> dist) {
        vertex *u = V[start];
        vertex *v = V[end];
        u->edges.push_back(edge(v,dist));
    }
    in.close();
}

graph::~graph() {
    std::map<char,vertex*>::iterator itr = V.begin();
    while(itr != V.end()) {
        delete itr->second;
        itr++;
    }
}

void graph::dijkstra(char s) {
    fHeap Q;
    
    int j = 0;
    while(j < verts.size()) {
        vertex *v = verts[j];
        if(v->key != s) {
            v->d = INF;
            v->p = nullptr;
        } else {
            v->d = 0;
            v->p = v;
        }
        v->node = Q.insert(v);
        j++;
    }
    
    while(!Q.empty() ) {
        vertex* u = Q.extractMin();
        
        std::vector<edge>& edges = u->edges;
        std::vector<edge>::iterator itr2 = edges.begin();
        while(itr2 != edges.end()) {
            vertex* v = itr2->v;
            if(u->d + itr2->weight < v->d) {
                v->d = u->d + itr2->weight;
                v->p = u;
                Q.decreaseKey(v->node);
            }
            itr2++;
        }
    }
}

void graph::pathTo(char dest,std::list<char>& L)
{
    vertex *v = V[dest];
    if(v->d == 0)
        L.push_back(dest);
    else if(v->p == nullptr)
        return;
    else {
        this->pathTo(v->p->key,L);
        L.push_back(dest);
    }
}
