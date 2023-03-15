#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    int last = n - 1;
    for (int i = 0; i < last; ++i) {
        int minValue = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < minValue) {
                minValue = arr[j];
                minIndex = j;
            }
        }
        // swap
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
}

int main() {
    int arr[] = {45, 56, 78, 99, 29, 81};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, n);

    cout << "SelectionSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

