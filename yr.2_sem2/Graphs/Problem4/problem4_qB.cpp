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
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (auto adjacent : adj[current]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
}

int main() {
    Graph g(9);
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

    cout << "Breadth First Traversal starting from vertex 1: ";
    g.BFS(1);

    return 0;
}
