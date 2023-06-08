#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

void shellSort(int arr[], int n) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, n - 1);

  // initialize array with random values
  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }

  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }

/*   // print sorted array
  cout << "Sorted Array: " << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl; */
}

int main() {
  int n = 100;
  int arr[n];

  cout << "\nInput Size: " << n << endl;
  auto start = chrono::high_resolution_clock::now();
  shellSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Time taken by Shell Sort Algorithm: " << fixed << setprecision(1)
       << duration.count() << " microseconds" << endl;

  return 0;
}
