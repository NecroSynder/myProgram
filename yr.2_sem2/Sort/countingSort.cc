#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>


using namespace std;

void countingSort(int arr[], int n) {
  // determine the range of input values
  int max_val = *max_element(arr, arr + n);
  int min_val = *min_element(arr, arr + n);

  // initialize count array
  int *count = new int[max_val - min_val + 1]();

  // count the frequency of each input value
  for (int i = 0; i < n; i++) {
    count[arr[i] - min_val]++;
  }

  // compute the cumulative count array
  for (int i = 1; i < max_val - min_val + 1; i++) {
    count[i] += count[i - 1];
  }

  // create a temporary output array
  int *output = new int[n];

  // iterate over the input array in reverse order to maintain stability
  for (int i = n - 1; i >= 0; i--) {
    int index = count[arr[i] - min_val] - 1;
    output[index] = arr[i];
    count[arr[i] - min_val]--;
  }

  // copy the output array to the input array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  // free memory
  delete[] count;
  delete[] output;
}

int main() {
  int n = 1000000;
  int *arr = new int[n];

  cout << "\nInput Size: " << n << endl;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, n - 1);

  // initialize array with random values
  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }

  auto start = chrono::high_resolution_clock::now();
  countingSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Counting Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  // free memory
  delete[] arr;

  return 0;
}
