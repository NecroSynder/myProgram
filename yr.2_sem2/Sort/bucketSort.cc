#include <chrono>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

void bucketSort(int arr[], int n) {
  // determine the range of input values
  int max_val = *max_element(arr, arr + n);
  int min_val = *min_element(arr, arr + n);

  // determine the number of buckets and their size
  const int num_buckets = sqrt(n);
  const int bucket_size = ceil((max_val - min_val + 1.0) / num_buckets);

  // initialize buckets
  int* buckets[num_buckets];
  for (int i = 0; i < num_buckets; i++) {
    buckets[i] = new int[n];
  }
  int bucket_sizes[num_buckets] = {0};

  // distribute input values into buckets
  for (int i = 0; i < n; i++) {
    int bucket_index = (arr[i] - min_val) / bucket_size;
    buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
  }

  // sort each bucket using a comparison-based sort (e.g., insertion sort)
  for (int i = 0; i < num_buckets; i++) {
    sort(buckets[i], buckets[i] + bucket_sizes[i]);
  }

  // concatenate the sorted buckets into the output array
  int index = 0;
  for (int i = 0; i < num_buckets; i++) {
    for (int j = 0; j < bucket_sizes[i]; j++) {
      arr[index++] = buckets[i][j];
    }
    delete[] buckets[i];
  }
}

int main() {
  int n = 1000000;
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
  bucketSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Bucket Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  return 0;
}
