#include "graph.h"

int main()
{
    int n, m;

    cout << "Input number of vertices" << endl;
    cin >> n;
    cout << "Input number of edges" << endl;
    cin >> m;
    Edge* edges = new Edge[m];

    cout << "Input edges in the format: v1(int) v2(int) weight(int)" << endl;
    cout << "Type q to quit" << endl;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, weight;
        while (cin >> v1)
        {
            if ((char)v1 == 'q')
                break;
            cin >> v2 >> weight;
            edges[i] = Edge{v1, v2, weight};
            break;
        }
        if ((char)v1 == 'q')
            break;
    }

    Graph g{n, edges, m};

    while (true)
    {
        cout << "Options: dfs bfs q" << endl;
        string option;
        cin.clear();
        while (cin >> option)
        {

            if (option == "bfs")
            {
                cout << "Input v(name) to output all connected vertices, or b to go back" << endl;
                int v;
                cin >> v;

                if (v == 'b')
                {
                    break;
                }

                if (v > n)
                {
                    cout << "ERROR: requested vertex too large" << endl;
                    break;
                }

                g.depth_first_search(g.head[v - 1]);
            }

            else if (option == "dfs")
            {
                cout << "Input v(name) to output all connected vertices, or b to go back" << endl;
                int v;
                cin >> v;

                if (v == 'b')
                {
                    break;
                }

                if (v > n)
                {
                    cout << "ERROR: requested vertex too large" << endl;
                    break;
                }
                g.depth_first_search(g.head[v - 1]);
            }

            else if (option == "q")
            {
                break;
            }
        }
    }
}