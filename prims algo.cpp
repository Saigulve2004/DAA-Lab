#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << "\n";
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Stores the constructed MST
    int key[V];     // Key values for minimum edge selection
    bool mstSet[V]; // True if vertex is included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;    // Include first vertex
    parent[0] = -1; // First node is always the root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Get the minimum key vertex
        mstSet[u] = true; // Include it in MST

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }

    printMST(parent, graph);
}

// Driver code
int main() {
    int graph[V][V];

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    auto start = high_resolution_clock::now(); // Start time measurement

    primMST(graph); // Run Prim's Algorithm

    auto end = high_resolution_clock::now(); // End time measurement
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}
