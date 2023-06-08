#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>


using namespace std;

void mergeSort(int array[], int const left, int const mid, int const right) {

  auto const subArrayOne = mid - left + 1;
  auto const subArrayTwo = right - mid;

  auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++) {
    leftArray[i] = array[left + i];
  }
  for (auto j = 0; j < subArrayTwo; j++) {
    rightArray[j] = array[mid + 1 + j];
  }

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergeArray = left;

  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergeArray++;
  }

  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergeArray++;
  }

  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergeArray++;
  }

  delete[] leftArray;
  delete[] rightArray;
}

void mergeStart(int array[], int const begin, int const end) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, end - begin);

  // initialize array with random values
  for (int i = begin; i <= end; i++) {
    array[i] = dis(gen);
  }

  if (begin >= end)
    return;

  auto mid = begin + (end - begin) / 2;
  mergeStart(array, begin, mid);
  mergeStart(array, mid + 1, end);
  mergeSort(array, begin, mid, end);
}

int main() {
  int n = 100;
  int *arr = new int[n];

  cout << "\nInput Size: " << n << endl;
  auto start = chrono::high_resolution_clock::now();
  mergeStart(arr, 0, n - 1);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Merge Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  delete[] arr;

  return 0;
}
