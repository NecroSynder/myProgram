#include <chrono>
#include <climits>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int Bubble_Sort(int arr[], int n) {
  // Bubble sort
  if (n < 3) {
    // Handle error
    return INT_MIN;
  }
  bool sorted = true;
  for (int i = 0; i < n - 1; i++) {
    sorted = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        sorted = false;
      }
    }
    if (sorted) {
      break;
    }
  }
  // Find third maximum
  int maxCount = 1;
  int thirdMax = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      maxCount++;
      if (maxCount == 3) {
        thirdMax = arr[i];
        break;
      }
    }
  }
  return thirdMax;
}

int bogosort(int arr[], int n) {
  if (n < 3) {
    // Handle error
    return INT_MIN;
  }
  bool sorted = true;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, RAND_MAX);
  while (true) {
    sorted = true;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        sorted = false;
        break;
      }
    }
    if (sorted) {
      break;
    }
    int i = dis(gen) % n;
    int j = dis(gen) % n;
    if (i < j && arr[i] > arr[j]) {
      swap(arr[i], arr[j]);
    }
  }

  int maxCount = 1;
  int thirdMax = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      maxCount++;
      if (maxCount == 3) {
        thirdMax = arr[i];
        break;
      }
    }
  }
  return thirdMax;
}

int main() {
  int n = 10000;
  int *arr = new int[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
  }

  auto start = chrono::high_resolution_clock::now();
  int thirdMax_Sort = Bubble_Sort(arr, n);
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Time taken by Bubble Sort algorithm: " << fixed << setprecision(1)
       << duration.count() << " milliseconds" << endl;

  cout << "Third maximum element in the array: " << thirdMax_Sort << endl;

  start = chrono::high_resolution_clock::now();
  int thirdMax_bogoSort = bogosort(arr, n);
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  cout << "Time taken by bogosort algorithm: " << fixed << setprecision(1)
       << duration.count() << " milliseconds" << endl;

  cout << "Third maximum element in the array: " << thirdMax_bogoSort << endl;

  delete[] arr; // deallocate memory
  return 0;
}