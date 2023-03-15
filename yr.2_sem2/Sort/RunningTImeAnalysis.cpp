#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void bubbleSort(int arr[], int size) {
    bool swapped = true;
    int j = 0;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
}

int main() {
    std::srand(std::time(nullptr));  // seed the random number generator
    std::vector<std::pair<int, double>> results;

    for (int size = 100; size < INT_MAX; size *= 10) {
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = std::rand() % size;
        }

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, size);
        auto end = std::chrono::high_resolution_clock::now();

        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        results.push_back(std::make_pair(size, elapsed_time));
        delete[] arr;
    }

    // Plot the results
    std::vector<int> input_sizes;
    std::vector<double> running_times;
    for (const auto& result : results) {
        input_sizes.push_back(result.first);
        running_times.push_back(result.second);
    }

    plt::plot(input_sizes, running_times);
    plt::xlabel("Input Size");
    plt::ylabel("Running Time (ms)");
    plt::show();

    return 0;
}
