#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Edge
{
    int start, end, weight;
};

struct Vertex
{
    int value;
    int cost;
    Vertex *next;
};

class Graph
{
    int n;
public:
    map<Vertex*, bool> visited;
    Vertex **head;
    Graph(int n, Edge edges[], int m);
    ~Graph();
    int find(string temp, int i);
    void breadth_first_search(Vertex *s);
    void depth_first_search(Vertex *s);
};
