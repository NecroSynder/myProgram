#include <climits>
#include <iostream>

using namespace std;

class ThirdMax {
private:
  int arr[10];

public:
  void contentArr() {
    cout << "Enter 10 integers: " << endl;
    for (int i = 0; i < 10; i++) {
      cin >> arr[i];
    }
  }

  void bubbleSort() {   // First Algorithm for getting the Third Max
    int temp;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 9 - i; j++) { // Fixed loop bounds
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }

  int findThirdMax() {   // Second Algorithm based from Vince Loable for getting the Third Max
    int firstMax = arr[0], secondMax = arr[0], thirdMax = arr[0];
    for (int i = 0; i < 10; i++) {
      if (arr[i] > firstMax) {
        thirdMax = secondMax;
        secondMax = firstMax;
        firstMax = arr[i];
      } else if (arr[i] > secondMax && arr[i] < firstMax) {
        thirdMax = secondMax;
        secondMax = arr[i];
      } else if (arr[i] > thirdMax && arr[i] < secondMax) {
        thirdMax = arr[i];
      }
    }
    return thirdMax;
  }

  int findMax(int arr[], int n) {   // The algorithm presented by our instructor...  
    int max = arr[0];               // ...that is implemeted and this is sub function for the findThirdMax_MaaamEmily.
    for (int i = 0; i < n; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }

  void copyArrayWithoutMax(int arr1[], int arr2[], int n, int max) {    // This is the continued sub function for the findThirdMax_MaaamEmily.
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (arr1[i] != max) {
        arr2[j] = arr1[i];
        j++;
      }
    }
  }

  int findThirdMax_MaamEmily() {    // This is the main function for the sub function "copyArrayWithoutMax" and "findMax".
    int max1 = findMax(arr, 10);
    int arr2[9];
    copyArrayWithoutMax(arr, arr2, 10, max1);
    int arr3[8];
    int max2 = findMax(arr2, 9);
    copyArrayWithoutMax(arr2, arr3, 9, max2);
    int thirdMax = findMax(arr3, 8);

    return thirdMax;
  }

  int getThirdMax() {   // The getter function for the value that being sorted from the three algorithms.
    if (arr[7] != arr[8]) {
      return arr[7];
    } else if (arr[6] != arr[7]) {
      return arr[6];
    } else {
      return arr[5];
    }
  }
};

int main() {
  ThirdMax algo;

  algo.contentArr();

  int thirdMax = algo.getThirdMax();

  algo.bubbleSort();
  cout << "THE THIRD MAX IN SORTING is: " << thirdMax << endl;

  algo.findThirdMax();
  cout << "THE THIRD MAX IN ALGORITHM 2 is: " << thirdMax << endl;

  algo.findThirdMax_MaamEmily();
  cout << "THE THIRD MAX IN ALGORITHM 3 is: " << thirdMax << endl;

  return 0;
}
