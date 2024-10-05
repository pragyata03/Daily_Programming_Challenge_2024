#include <iostream>
#include <vector>
using namespace std;

// A helper function to perform DFS and detect cycles
bool dfsCycleDetect(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    // Traverse all adjacent vertices
    for (int neighbor : graph[node]) {
        // If the neighbor is not visited, recursively find
        if (!visited[neighbor]) {
            if (dfsCycleDetect(neighbor, node, graph, visited))
                return true;
        }
        // If the neighbor is visited and is not the parent, there is a cycle
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Function to check if the graph has a cycle
bool containsCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> graph(V);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleDetect(i, -1, graph, visited))
                return true;
        }
    }
    return false;
}

// Main function
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}
    };
    if (containsCycle(V, edges)) {
        cout << "Cycle detected in the graph.\n";
        cout<< "True";
    } else {
        cout << "No cycle in the graph.\n";
        cout<< "False";
    }
    return 0;
}
