#include "graph.h"

int Vertex::edgeFind(string v2)
{
    for (int i = 0; i < edges.size(); ++i)
        if (edges[i]->name == v2) return i;

    return -1;
}

Graph::Graph(int n, int m) : n{n}, m{m}
{}

int Graph::find(string temp, int i)
{
    for (int j = 0; j < i; ++j)
        if (vertices[j]->name == temp)
        {
            return j;
        }
    return -1;
}

void Graph::breadth_first_search(int i, int n)
{
    bool visited[n] = {false};
    if (s->edges.size() == 0)
    {
        cout << "Connected to none" << endl;
        return;
    }
    queue<Vertex *> q;
    q.push(s);
    visited[s] = true;
    while (q.size() != 0)
    {
        Vertex *u = q.front();
        q.pop();
        for (int k = 0; k < u->edges.size(); ++k)
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                cout << v->name << endl;
            }
    }
}