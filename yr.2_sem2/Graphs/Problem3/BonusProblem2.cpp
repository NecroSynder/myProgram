// Members:
//      GC Neal Christian S. Clarin

#include <iostream>
#include <vector>

std::vector<std::vector<int>> createAdjacencyMatrix(const std::vector<std::pair<int, int>>& edges, int n) {
    std::vector<std::vector<int>> adjacency_matrix(n, std::vector<int>(n, 0));

    for (const auto& edge : edges) {
        adjacency_matrix[edge.first - 1][edge.second - 1] = 1;
    }

    return adjacency_matrix;
}

void printAdjacencyMatrix(const std::vector<std::vector<int>>& adjacency_matrix) {
    for (const auto& row : adjacency_matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int countEdges(const std::vector<std::vector<int>>& adjacency_matrix) {
    int num_edges = 0;

    for (const auto& row : adjacency_matrix) {
        for (int value : row) {
            if (value == 1) {
                num_edges++;
            }
        }
    }

    return num_edges;
}

int main() {
    std::vector<std::pair<int, int>> edges = {
        {1, 2}, {2, 5}, {5, 3}, {3, 1},
        {5, 8}, {8, 6}, {6, 3},
        {8, 10}, {10, 9}, {9, 7}, {7, 8},
        {1, 4}, {4, 3},
        {4, 6},
        {4, 7}, {7, 8}
    };

    int n = 10; // Number of vertices

    std::vector<std::vector<int>> adjacency_matrix = createAdjacencyMatrix(edges, n);

    std::cout << "Adjacency Matrix:" << std::endl;
    printAdjacencyMatrix(adjacency_matrix);

    int num_edges = countEdges(adjacency_matrix);
    std::cout << "\nNumber of edges in the graph: " << num_edges << std::endl;

    return 0;
}
