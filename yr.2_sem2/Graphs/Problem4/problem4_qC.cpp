// Members:
//      GC Neal Christian S. Clarin

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    void DFSUtil(int s, vector<bool> &visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Add w to v's list as well since this is an undirected graph
}

void Graph::DFSUtil(int s, vector<bool> &visited) {
    visited[s] = true;
    cout << s << " ";

    for (auto adjacent : adj[s]) {
        if (!visited[adjacent]) {
            DFSUtil(adjacent, visited);
        }
    }
}

void Graph::DFS(int s) {
    vector<bool> visited;
    visited.resize(V, false);

    DFSUtil(s, visited);
}

int main() {
    Graph g(9); // Create a graph with 9 vertices (0 to 8)
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 6);
    g.addEdge(2, 3);
    g.addEdge(3, 7);
    g.addEdge(3, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    cout << "Depth First Traversal starting from vertex 1: ";
    g.DFS(1);

    return 0;
}
