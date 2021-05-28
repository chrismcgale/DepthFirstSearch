#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
    string name;
    vector<Vertex *> edges;
    int edgeFind(string v2);
};

class Graph {
    int n, m;
    Vertex* vertices[];
    bool* visited;
    public:
    Graph(int n, int m);
    int find(string temp, int i);
    void breadth_first_search(int i);
    void depth_first_search(Vertex* s);
    void setVisited();
    void delVisited() { delete visited; }
    Vertex** getVertices() { return vertices; }
};
