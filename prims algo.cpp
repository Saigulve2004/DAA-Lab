#include <bits/stdc++.h>
using namespace std;

#define V 3 // Number of vertices

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
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE and MST set as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include the first vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex not in MST
        mstSet[u] = true;            // Include the picked vertex in MST

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph);
}

// Main function
int main() {
    int graph[V][V];

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "\nPrim's Algorithm - Minimum Spanning Tree:\n";
    primMST(graph);

    return 0;
}

