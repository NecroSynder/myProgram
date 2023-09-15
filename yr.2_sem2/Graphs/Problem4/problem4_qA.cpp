// Members:
//      GC Neal Christian S. Clarin

#include <iostream>
#include <vector>
#include <iomanip> // for setw and left

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int vertices) {
        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int i, int j) {
        adjacencyMatrix[i - 1][j - 1] = 1;
        adjacencyMatrix[j - 1][i - 1] = 1;
    }

    void printMatrix() {
        for (const auto &row : adjacencyMatrix) {
            for (int value : row) {
                cout << setw(3) << left << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(8);

    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(1, 6);
    graph.addEdge(2, 6);
    graph.addEdge(2, 3);
    graph.addEdge(3, 7);
    graph.addEdge(3, 6);
    graph.addEdge(3, 4);
    graph.addEdge(4, 7);
    graph.addEdge(4, 8);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);

    graph.printMatrix();

    return 0;
}
