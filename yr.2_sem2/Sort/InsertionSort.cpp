#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int currValue = arr[i];
        int posValue = i;
        while (posValue > 0 && currValue < arr[posValue - 1]) {
            arr[posValue] = arr[posValue - 1];
            posValue = posValue - 1;
        }
        arr[posValue] = currValue;
    }
}

int main() {
    int arr[] = {45, 56, 78, 99, 29, 81};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}