#include <climits>
#include <iostream>

using namespace std;

class ThirdMax {
private:
  int arr[10];

public:
  /* void contentArr() {
    cout << "Enter 10 integers: " << endl;
    for (int i = 0; i < 10; i++) {
      cin >> arr[i];
    }
  } */

  void contentArr() {
    cout << "Enter 10 integers: " << endl;
    for (int i = 0; i < 10; i++) {
      while (!(cin >> arr[i])) {
        cout << "Invalid input, please enter an integer: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
      }
    }
  }

  void bubbleSort() {   // First Algorithm for getting the Third Max
    int temp;
    for (int i = 0; i < 9; i++) { // Fixed loop bounds
      for (int j = 0; j < 9 - i; j++) { 
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }

  int getThirdMax() {
    bubbleSort(); // sort the array first
    if (arr[7] != arr[8]) {
      return arr[7];
    } else if (arr[6] != arr[7]) {
      return arr[6];
    } else {
      return arr[5];
    }
  }

  int findThirdMax() {   // Second Algorithm based from Vince Loable for getting the Third Max
    int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN; // initialize with the smallest possible integer value
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
    int max = arr[0];               // ...that is implemented and this is sub function for the findThirdMax_MaaamEmily.
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

  
};

int main() {
ThirdMax algo;

algo.contentArr();
int thirdMax = algo.getThirdMax();
cout << "THE THIRD MAX IN ALGORITHM 1 is: " << thirdMax << endl;

thirdMax = algo.findThirdMax(); // assign the result of findThirdMax() to thirdMax
cout << "THE THIRD MAX IN ALGORITHM 2 is: " << thirdMax << endl;

thirdMax = algo.findThirdMax_MaamEmily(); // assign the result of findThirdMax_MaamEmily() to thirdMax
cout << "THE THIRD MAX IN ALGORITHM 3 is: " << thirdMax << endl;

return 0;
}
