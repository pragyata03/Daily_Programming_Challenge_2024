#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to perform BFS and track parent nodes and distances from the source
void bfs_Traversal(const vector<vector<int>>& graph, int start, vector<int>& parent, vector<int>& distance) {
    queue<int> q;
    distance[start] = 0;  // Source node distance is 0
    q.push(start);

    while (!q.empty()) {
        int current_Node = q.front();
        q.pop();
        for (int neighbor : graph[current_Node]) {
            if (distance[neighbor] == INT_MAX) {
                parent[neighbor] = current_Node;
                distance[neighbor] = distance[current_Node] + 1;
                q.push(neighbor);
            }
        }
    }
}

// Function to print the shortest path between source and destination
void print_Shortest_Path(const vector<vector<int>>& graph, int source, int destination, int vertices) {
    vector<int> parent(vertices, -1);    
    vector<int> distance(vertices, INT_MAX);  
    bfs_Traversal(graph, source, parent, distance);  // Perform BFS to find shortest path
    // If destination is unreachable
    if (distance[destination] == INT_MAX) {
        cout << "Source and destination are not connected" << endl;
        return;
    }
    // Store the path from destination to source by following parent pointers
    vector<int> path;
    for (int node = destination; node != -1; node = parent[node]) {
        path.push_back(node);
    }
    // Output the path in reverse order (from source to destination)
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int V = 8, E = 10;  // Number of vertices and edges
    int source = 2, destination = 6;  // Source and destination vertices

    // List of edges defining the graph
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {0, 3}, {3, 4},
        {4, 7}, {3, 7}, {6, 7}, {4, 5},
        {4, 6}, {5, 6}
    };
    // Adjacency list representation of the graph
    vector<vector<int>> graph(V);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    // Print the shortest path from source to destination
    print_Shortest_Path(graph, source, destination, V);

    return 0;
}
