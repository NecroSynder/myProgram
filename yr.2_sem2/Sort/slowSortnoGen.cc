#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void slowSort(int arr[], int n) {
  int i, j;

  bool sorted = false; // initialize sorted to false
  while (!sorted) {    // replace sorted with !sorted
    sorted = true;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (arr[i] > arr[j]) {
          swap(arr[i], arr[j]);
          sorted = false;
        }
      }
    }
  }
}

int main() {
  srand(time(0));
  int a[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(a) / sizeof(int);
  slowSort(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
