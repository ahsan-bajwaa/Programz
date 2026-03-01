#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int v, int V, vector<int> G[])
{
    // Stack S := {}
    stack<int> S;

    // for each vertex u, visited[u] := false
    vector<bool> visited(V, false);

    // push S, v
    S.push(v);

    // while (S is not empty)
    while (!S.empty())
    {
        // u := pop S
        int u = S.top();
        S.pop();

        // if (not visited[u])
        if (!visited[u])
        {
            // visited[u] := true
            visited[u] = true;

            cout << u << " ";   // process u

            // for each unvisited neighbor w of u
            for (int w : G[u])
            {
                if (!visited[w])
                {
                    // push S, w
                    S.push(w);
                }
            }
        }
    }
}

int main()
{
    int V = 6;
    vector<int> G[V];

    G[0].push_back(1);
    G[0].push_back(2);
    G[1].push_back(3);
    G[1].push_back(4);
    G[2].push_back(5);

    DFS(0, V, G);
    return 0;
}
