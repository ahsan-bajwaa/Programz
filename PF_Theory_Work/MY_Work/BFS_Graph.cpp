#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int s, int V, vector<int> G[])
{
    // Let Q be a queue
    queue<int> Q;

    // visited array
    vector<bool> visited(V, false);

    // Q.enqueue(s)
    Q.push(s);

    // mark s as visited
    visited[s] = true;

    // while (Q is not empty)
    while (!Q.empty())
    {
        // v = Q.dequeue()
        int v = Q.front();
        Q.pop();

        cout << v << " ";   // processing node v

        // traversing all the neighbors of v
        for (int w : G[v])
        {
            // if w is not visited
            if (!visited[w])
            {
                // Q.enqueue(w)
                Q.push(w);

                // mark w as visited
                visited[w] = true;
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

    BFS(0, V, G);
    return 0;
}
