#include <iostream>
#include <vector>
#include <queue>
#include <cstddef> // For size_t
using namespace std;

// 1. Graph Construction Function
void createGraphFromEdges(int V, const vector<int>& edgeDataFlat, vector<int> G[])
{
    // Loop through the vector, incrementing the index by 2 each time
    for (size_t i = 0; i < edgeDataFlat.size(); i += 2)
    {
        // Safety check: ensure there is a pair (u, v) available
        if (i + 1 >= edgeDataFlat.size())
            break; 

        // Current element is the start vertex (u)
        int u = edgeDataFlat[i];
        
        // Next element is the end vertex (v)
        int v = edgeDataFlat[i + 1];

        // Add the directed edge u -> v
        G[u].push_back(v);
        
        // Note: For an undirected graph, you would also add: G[v].push_back(u);
    }
}

void BFS(int s, int V, vector<int> G[])
{
    // Use a queue for BFS (FIFO principle)
    queue<int> Q;

    // Use a vector to track visited nodes
    vector<bool> visited(V, false);

    // Initialize: Push the starting node and mark it as visited
    Q.push(s);
    visited[s] = true;

    // Main traversal loop
    while (!Q.empty())
    {
        // Dequeue the current node
        int v = Q.front();
        Q.pop();

        // Process the node (print its value)
        cout << v << " ";

        // Traverse all neighbors (w) of the current node (v)
        for (int w : G[v])
        {
            // If the neighbor has not been visited
            if (!visited[w])
            {
                // Enqueue the neighbor and mark it as visited
                Q.push(w);
                visited[w] = true;
            }
        }
    }
}


// --- 3. Main Program Execution ---
int main()
{
    const int V = 6;
    
    // Declare the Adjacency List: an array of V vectors of integers
    vector<int> G[V];

    // Define the graph data using a simple, flattened vector<int>
    // Edge format: {u1, v1, u2, v2, u3, v3, ...}
    vector<int> edgeDataFlat = {
        0, 1, // Edge from 0 to 1
        0, 2, // Edge from 0 to 2
        1, 3, // Edge from 1 to 3
        1, 4, // Edge from 1 to 4
        2, 5  // Edge from 2 to 5
    };

    // Build the graph structure by calling the function
    createGraphFromEdges(V, edgeDataFlat, G);

    cout << "Graph structure built successfully from array data." << endl;
    cout << "BFS Traversal (starting at node 0): ";
    
    // Run the BFS algorithm
    BFS(0, V, G);
    cout << endl; // Final newline for clean output

    return 0;
}