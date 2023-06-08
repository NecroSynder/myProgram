#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

void radixSort(int arr[], int n) {
  // determine the maximum value in the input array
  int max_val = *max_element(arr, arr + n);

  // determine the number of digits in the maximum value
  int num_digits = 0;
  while (max_val > 0) {
    max_val /= 10;
    num_digits++;
  }

  // initialize the output array and bucket array
  int *output = new int[n];
  int *bucket = new int[10]();

  // iterate over each digit, starting with the least significant digit
  for (int digit = 0; digit < num_digits; digit++) {
    // reset the bucket array
    fill_n(bucket, 10, 0);

    // count the frequency of each digit in the input array
    for (int i = 0; i < n; i++) {
      int digit_val = (arr[i] / static_cast<int>(pow(10, digit))) % 10;
      bucket[digit_val]++;
    }

    // compute the cumulative count array
    for (int i = 1; i < 10; i++) {
      bucket[i] += bucket[i - 1];
    }

    // iterate over the input array in reverse order to maintain stability
    for (int i = n - 1; i >= 0; i--) {
      int digit_val = (arr[i] / static_cast<int>(pow(10, digit))) % 10;
      int index = bucket[digit_val] - 1;
      output[index] = arr[i];
      bucket[digit_val]--;
    }

    // copy the output array to the input array
    for (int i = 0; i < n; i++) {
      arr[i] = output[i];
    }
  }

  // deallocate memory
  delete[] output;
  delete[] bucket;
}

int main() {
  int n = 2000000;
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
  radixSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Radix Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  // deallocate memory
  delete[] arr;

  return 0;
}
