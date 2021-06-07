#include "graph.h"


Graph::Graph(int n, Edge edges[], int m) : n{n}
{
    head = new Vertex *[n]();
    for (int i = 0; i < n; ++i)
        head[i] = new Vertex{i + 1, 0, nullptr};
    for (int j = 0; j < m; ++j)
    {
        int start = edges[j].start;
        int weight = edges[j].weight;
        int end = edges[j].end;

        head[start - 1]->next = head[end - 1];
        head[end - 1]->next = head[start - 1];
    }
}

Graph::~Graph()
{
    for (int i = 0; i < n; ++i) delete[] head[i];
    delete [] head;
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
            if(v == s) break;
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
        if(u == s) break;
    }
}