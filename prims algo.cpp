#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define V 5  // Number of vertices in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// Find function for Disjoint Set (used in Kruskal)
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Union function for Disjoint Set
void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

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

// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V];  
    int key[V];     
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }

    printMST(parent, graph);
}

// Function to implement Kruskal's Algorithm
void kruskalMST(Graph& graph) {
    vector<Edge> result;
    int parent[V];
    memset(parent, -1, sizeof(parent));

    // Sorting edges by weight
    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    for (Edge e : graph.edges) {
        int x = find(parent, e.src);
        int y = find(parent, e.dest);

        if (x != y) {
            result.push_back(e);
            Union(parent, x, y);
        }
    }

    cout << "Edge \tWeight\n";
    for (auto e : result)
        cout << e.src << " - " << e.dest << " \t" << e.weight << "\n";
}

int main() {
    int graph[V][V];

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    // Construct Graph for Kruskal's Algorithm
    Graph g;
    g.V = V;
    g.E = 0;
    
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                g.edges.push_back({i, j, graph[i][j]});
                g.E++;
            }
        }
    }

    auto start_prim = high_resolution_clock::now();
    cout << "\nPrim's Algorithm:\n";
    primMST(graph);
    auto end_prim = high_resolution_clock::now();
    auto duration_prim = duration_cast<microseconds>(end_prim - start_prim);

    auto start_kruskal = high_resolution_clock::now();
    cout << "\nKruskal's Algorithm:\n";
    kruskalMST(g);
    auto end_kruskal = high_resolution_clock::now();
    auto duration_kruskal = duration_cast<microseconds>(end_kruskal - start_kruskal);

    cout << "\nExecution time:\n";
    cout << "Prim's Algorithm: " << duration_prim.count() << " microseconds\n";
    cout << "Kruskal's Algorithm: " << duration_kruskal.count() << " microseconds\n";

    return 0;
}
