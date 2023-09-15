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
  void shortestPath(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new vector<iPair>[V];
  parent.resize(V, -1);
}

void Graph::addEdge(int u, int v, int w) { adj[u].push_back(make_pair(v, w)); }

void printPath(const vector<int> &parent, int dest) {
  if (parent[dest] == -1) {
    cout << dest << " ";
    return;
  }
  printPath(parent, parent[dest]);
  cout << dest << " ";
}

void Graph::shortestPath(int src) {
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  vector<int> dist(V, numeric_limits<int>::max());
  parent[src] = -1;

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
      int v = (*i).first;
      int weight = (*i).second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  vector<pair<int, int>> sortedDistances;
  for (int i = 0; i < V; ++i)
    sortedDistances.push_back(make_pair(dist[i], i));

  sort(sortedDistances.begin(), sortedDistances.end());

  cout << "Shortest paths from vertex 1 in ascending order of length:" << endl;
  for (const auto &entry : sortedDistances) {
    if (entry.second == src ||
        (entry.second == 0 && entry.first == numeric_limits<int>::max()))
      continue;
    cout << "Path to vertex " << entry.second << ": ";
    printPath(parent, entry.second);
    cout << "Length: " << entry.first << endl;
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

  g.shortestPath(1);

  return 0;
}
