#include "graph.h"


int main()
{
    int n, m;

    cout << "Input number of vertices" << endl;
    cin >> n;

    cout << "Input number of edges" << endl;
    cin >> m;
    Graph graph(n, m);

    cout << "Input unique names of each vertex";
    for (int i = 0; i < n; ++n)
    {
        string temp;
        while (cin >> temp)
        {
            if (graph.find(temp, i) != -1)
            {
                graph.getVertices()[i]->name = temp;
                break;
            }
            else
                cerr << "ERROR: REPEAT NAME" << endl;
        }
    }


    cout << "Input edges in the format: v1(name) v2(name)" << endl;
    string v1, v2;
    for (int j = 0; j < m; ++j)
    {
        while (cin >> v1 >> v2)
        {
            int p1 = graph.find(v1, n);
            if (p1 == -1)
            {
                cerr << "ERROR: v1 has an INVALID NAME" << endl;
                continue;
            }

            int p2 = graph.find(v2, n);
            if (p2 == -1)
            {
                cerr << "ERROR: v2 has an INVALID NAME" << endl;
                continue;
            }

            //edges find
            int p = graph.getVertices()[p1]->edgeFind(v2);

            if (p != -1)
            {
                cerr << "ERROR: REPEAT EDGE" << endl;
                continue;
            }

            graph.getVertices()[p1]->edges.push_back(graph.getVertices()[p2]);
            graph.getVertices()[p2]->edges.push_back(graph.getVertices()[p1]);
            break;
        }
    }

    while (true)
    {
        cout << "Input v(name) to output all connected vertices, or q to quit" << endl;
        string v;
        cin >> v;

        int f = graph.find(v1, n);
        if (f == -1)
        {
            cerr << "ERROR: INVALID NAME" << endl;
            continue;
        }
        graph.breadth_first_search(f, n);
    }
}