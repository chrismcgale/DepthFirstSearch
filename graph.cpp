#include "graph.h"

Graph::Graph(int n, Edge edges[], int m) : n{n}
{
    head = new Vertex *[n]();
    for (int i = 0; i < n; ++i)
        head[i] = nullptr;
    for (int j = 0; j < n; ++j)
    {
        int start = edges[j].start_ver;
        int weight = edges[j].weight;

        head[start] = new Vertex{start, weight, head[start]};
    }
}

Graph::~Graph()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] head[i];
        delete[] head;
    }
}

void Graph::breadth_first_search(Vertex *s)
{
    if (s->next == nullptr)
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
        Vertex *v = u->next;
        while (v != nullptr)
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                cout << v->value << endl;
            }
            v = v->next;
        }
    }
}

// could implement as stack but this works the same and same time compl.
void Graph::depth_first_search(Vertex *s)
{
    visited[s] = true;
    Vertex* u = s;
    while (u != nullptr)
    {
        if (visited[u] == false)
        {
            cout << u->value << endl;
            depth_first_search(u);
        }
        u = u->next;
    }
}