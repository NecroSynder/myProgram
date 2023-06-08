#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip> 
#include <random>
using namespace std;

int Bubble_Sort(int arr[], int n) {
    // Bubble sort
    if (n < 3) {
        // Handle error
        return -1;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void copyArrayWithoutMax(int arr1[], int arr2[], int n, int max) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr1[i] != max) {
            arr2[j] = arr1[i];
            j++;
        }
    }
    // If max occurs multiple times, remove all occurrences
    while (j < n - 1) {
        arr2[j] = arr1[j+1];
        j++;
    }
}

int findThirdMax_instructor_Algo(int arr1[], int n) {
    int max1 = findMax(arr1, n);
    int arr2[n - 1];
    copyArrayWithoutMax(arr1, arr2, n, max1);
    int arr3[n - 2];
    int max2 = findMax(arr2, n - 1);
    copyArrayWithoutMax(arr2, arr3, n - 1, max2);
    int max3 = findMax(arr3, n - 2);
    return max3;
}

int findThirdMax_Vince_Algo(int arr[], int n) {
    if (n < 3) {
        // handle error case
        return -1;
    }
    int firstMax = arr[0], secondMax = arr[1], thirdMax = arr[2];
    for (int i = 3; i < n; i++) {
        if (arr[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] != firstMax) {
            thirdMax = secondMax;
            secondMax = arr[i];
        }
        else if (arr[i] > thirdMax && arr[i] != secondMax && arr[i] != firstMax) {
            thirdMax = arr[i];
        }
    }
    return thirdMax;
}

int main() {
    int n = 10000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
    arr[i] = rand();
    }

    auto start = chrono::high_resolution_clock::now();
    int thirdMax_Sort = Bubble_Sort(arr, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Bubble Sort algorithm: " << fixed << setprecision(1) << duration.count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    int thirdMax_Instructor = findThirdMax_instructor_Algo(arr, n);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Instructor algorithm: " << fixed << setprecision(1) << duration.count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    int thirdMax_Vince = findThirdMax_Vince_Algo(arr, n);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Vince algorithm: " << fixed << setprecision(1) << duration.count() << " ms" << endl;

    
    return 0;
}

