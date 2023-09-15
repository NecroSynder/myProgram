// Members:
//      GC Neal Christian S. Clarin

#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> iPair;

class Graph {
  int V;
  vector<iPair> *adj;
  vector<int> parent;

public:
  Graph(int V);
  void addEdge(int u, int v, int w);
  void bfs(int s);
  const vector<int>& getParent() const;
};

Graph::Graph(int V) {
  this->V = V;
  adj = new vector<iPair>[V];
  parent.resize(V, -1);
}

const vector<int>& Graph::getParent() const {
  return parent;
}

void Graph::addEdge(int u, int v, int w) { adj[u].push_back(make_pair(v, w)); }

void Graph::bfs(int src) {
  queue<int> q;
  vector<bool> visited(V, false);
  parent[src] = -1;
  visited[src] = true;

  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
      int v = (*i).first;

      if (!visited[v]) {
        visited[v] = true;
        parent[v] = u;
        q.push(v);
      }
    }
  }
}

void printTreeHelper(const vector<int>& parent, int node) {
  if (parent[node] != -1) {
    printTreeHelper(parent, parent[node]);
    cout << "->";
  }
  cout << node;
}

void printTree(const vector<int>& parent, int root) {
  for (int i = 1; i < parent.size(); ++i) {
    if (i != root) {
      printTreeHelper(parent, i);
      cout << endl;
    }
  }
}


int main() {
  Graph g(11);

  g.addEdge(1, 2, 2);
  g.addEdge(2, 5, 1);
  g.addEdge(5, 3, 7);
  g.addEdge(3, 1, 3);
  g.addEdge(2, 5, 1);
  g.addEdge(5, 8, 3);
  g.addEdge(8, 6, 2);
  g.addEdge(6, 3, 1);
  g.addEdge(3, 1, 3);
  g.addEdge(2, 5, 1);
  g.addEdge(5, 8, 3);
  g.addEdge(8, 10, 2);
  g.addEdge(10, 9, 1);
  g.addEdge(9, 7, 2);
  g.addEdge(7, 8, 1);
  g.addEdge(8, 6, 2);
  g.addEdge(6, 3, 1);
  g.addEdge(3, 1, 3);
  g.addEdge(1, 4, 20);
  g.addEdge(4, 3, 8);
  g.addEdge(3, 1, 3);
  g.addEdge(1, 4, 20);
  g.addEdge(4, 6, 6);
  g.addEdge(6, 3, 1);
  g.addEdge(3, 1, 3);
  g.addEdge(1, 4, 20);
  g.addEdge(4, 7, 4);
  g.addEdge(7, 8, 1);
  g.addEdge(8, 6, 2);
  g.addEdge(6, 3, 1);
  g.addEdge(3, 1, 3);

  g.bfs(1);
  cout << "Breadth-first spanning tree:" << endl;
  printTree(g.getParent(), 1);

  return 0;
}
