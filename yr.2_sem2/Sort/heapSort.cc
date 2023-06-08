#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

void heapify(int arr[], int N, int i) {
  int largest = i;

  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < N && arr[l] > arr[largest])
    largest = l;

  if (r < N && arr[r] > arr[largest])
    largest = r;

  if (largest != i){
    swap(arr[i], arr[largest]);

    heapify(arr, N, largest);
  }
}

void heapSort(int arr[], int N){
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);

  for (int i = N - 1; i > 0; i--){
    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

int main() {
  int n = 1000;
  int arr[n];

  cout << "\nInput Size: " << n << endl;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, n - 1);

  // initialize array with random values
  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }

  auto start = chrono::high_resolution_clock::now();
  heapSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Heap Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  return 0;
}
