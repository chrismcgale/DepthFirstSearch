#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
    string name;
    vector<Vertex *> edges;
};

int find(vector<Vertex*> vertices, string temp, int i)
{
    for (int j = 0; j < i; ++j)
        if (vertices[j]->name == temp)
        {
            return j;
        }
    return -1;
}

void breadth_first_search(vector<Vertex *> vertices, Vertex *s, int n)
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

int main()
{
    int n, m;

    cout << "Input number of vertices" << endl;
    cin >> n;

    cout << "Input unique names of each vertex";
    vector<Vertex *> graph;
    for (int i = 0; i < n; ++n)
    {
        string temp;
        while (cin >> temp)
        {
            if (find(graph, temp, i) != -1)
            {
                graph[i]->name = temp;
                break;
            }
            else
                cerr << "ERROR: REPEAT NAME" << endl;
        }
    }

    cout << "Input number of edges" << endl;
    cin >> m;

    cout << "Input edges in the format: v1(name) v2(name)" << endl;
    string v1, v2;
    for (int j = 0; j < m; ++j)
    {
        while (cin >> v1 >> v2)
        {
            int p1 = find(graph, v1, n);
            if (p1 == -1)
            {
                cerr << "ERROR: v1 has an INVALID NAME" << endl;
                continue;
            }

            int p2 = find(graph, v2, n);
            if (p2 == -1)
            {
                cerr << "ERROR: v2 has an INVALID NAME" << endl;
                continue;
            }

            int p = find(graph[p1]->edges, v2, graph[p1]->edges.size());

            if (p != -1)
            {
                cerr << "ERROR: REPEAT EDGE" << endl;
                continue;
            }

            graph[p1]->edges.push_back(graph[p2]);
            graph[p2]->edges.push_back(graph[p1]);
            break;
        }
    }

    while (true)
    {
        cout << "Input v(name) to output all connected vertices, or q to quit" << endl;
        string v;
        cin >> v;

        int f = find(graph, v1, n);
        if (f == -1)
        {
            cerr << "ERROR: INVALID NAME" << endl;
            continue;
        }
        breadth_first_search(graph, graph[f], n);
    }
}