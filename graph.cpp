#include "graph.h"

int Vertex::edgeFind(string v2)
{
    for (int i = 0; i < edges.size(); ++i)
        if (edges[i]->name == v2)
            return i;

    return -1;
}

Graph::Graph(int n, int m) : n{n}, m{m}
{
}

void Graph::setVisited()
{
    visited = new bool[n]{false};
}

int Graph::find(string temp, int i)
{
    for (int j = 0; j < i; ++j)
        if (vertices[j]->name == temp)
        {
            return j;
        }
    return -1;
}

void Graph::breadth_first_search(int i)
{
    Vertex *s = vertices[i];
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

void Graph::depth_first_search(Vertex *s)
{
    if (s->edges.size() == 0)
    {
        return;
    }
    visited[s] = true;
    for (int k = 0; k < s->edges.size(); ++k)
    {
        Vertex *v = s->edges[k];
        if (visited[v] == false)
        {
            visited[v] = true;
            cout << v->name << endl;
            depth_first_search(v);
        }
    }
}