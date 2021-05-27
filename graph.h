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
    public:
    Graph(int n, int m);
    int find(string temp, int i);
    void breadth_first_search(int i, int n);
    Vertex** getVertices() { return vertices; }
};
