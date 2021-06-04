#include "graph.h"

int main()
{
    int n, m;
    Edge *edges;

    cout << "Input number of vertices" << endl;
    cin >> n;
    cout << "Input number of vertices" << endl;
    cin >> m;

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
        }
        if ((char)v1 == 'q')
            break;
    }

    Graph g{n, edges, m};

    while (true)
    {
        cout << "Options: dfs bfs q" << endl;
        string option;
        while (cin >> option)
        {

            if (option == "bfs")
            {
                cout << "Input v(name) to output all connected vertices, or b to go back" << endl;
                char v;
                cin >> v;

                if (v == 'b')
                {
                    cout << "Options: dfs bfs q" << endl;
                    break;
                }

                if (int(v) > n)
                {
                    cout << "ERROR: requested vertex too large" << endl;
                    cout << "Options: dfs bfs q" << endl;
                    break;
                }

                // graph.setVisited();
                g.depth_first_search(g.head[(int)v]);
                //graph.delVisited();
            }

            else if (option == "dfs")
            {
                cout << "Input v(name) to output all connected vertices, or b to go back" << endl;
                char v;
                cin >> v;

                if (v == 'b')
                {
                    cout << "Options: dfs bfs q" << endl;
                    break;
                }

                if (int(v) > n)
                {
                    cout << "ERROR: requested vertex too large" << endl;
                    cout << "Options: dfs bfs q" << endl;
                    break;
                }
                //graph.setVisited();
                g.depth_first_search(g.head[(int)v]);
                //graph.delVisited();
            }

            else if (option == "q")
            {
                break;
            }
        }
    }
}