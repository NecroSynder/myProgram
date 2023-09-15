// Members:
//      GC Neal Christian S. Clarin

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> Edge;

vector<vector<Edge>> graph;
vector<int> parent;

int prims(int start) {
    int total_cost = 0;
    vector<bool> visited(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;
            total_cost += cost;

            // Print the edge information if the node is not the starting node
            if (parent[node] != -1) {
                cout << "Added edge: (" << parent[node] << ", " << node << ") with weight: " << cost << endl;
            }

            for (const Edge &edge : graph[node]) {
                if (!visited[edge.second]) {
                    pq.push(edge);
                    parent[edge.second] = node;
                }
            }
        }

    }

    return total_cost;
}

void printPath(int vertex, const vector<int> &parent) {
    if (parent[vertex] == -1) {
        cout << vertex;
        return;
    }
    printPath(parent[vertex], parent);
    cout << " -> " << vertex;
}

int main() {
    int n = 8;
    graph.resize(n + 1);
    parent.resize(n + 1, -1);
    // ... (same as before)
    vector<pair<int, pair<int, int>>> edges = {
        {1, {2, 2}}, {1, {5, 22}}, {1, {6, 8}}, {2, {1, 2}}, {2, {6, 6}}, {2, {3, 10}},
        {3, {2, 10}}, {3, {7, 1}}, {3, {6, 12}}, {3, {4, 3}}, {4, {3, 3}}, {4, {7, 5}},
        {4, {8, 20}}, {5, {1, 22}}, {5, {6, 25}}, {6, {5, 25}}, {6, {1, 8}}, {6, {2, 6}},
        {6, {3, 12}}, {6, {7, 11}}, {7, {6, 11}}, {7, {3, 1}}, {7, {4, 5}}, {7, {8, 15}},
        {8, {7, 15}}, {8, {4, 20}}
    };

    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second.first;
        int w = edge.second.second;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int cost = prims(1);
    cout << "\nMinimum cost of the spanning tree: " << cost << endl;

    cout << "\nPaths in the minimum cost spanning tree:" << endl;
    for (int i = 2; i <= n; ++i) {
        cout << "Path from 1 to " << i << ": ";
        printPath(i, parent);
        cout << endl;
    }

    return 0;
}
