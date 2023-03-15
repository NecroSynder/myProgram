#include <iostream>
#include <map>
using namespace std;

int main() {
    // Create a map with string keys and int values
    map<string, int> myMap;

    // Add some key-value pairs
    myMap["Alice"] = 42;
    myMap["Bob"] = 24;
    myMap["Charlie"] = 35;

    // Access a value by its key
    cout << "Alice's age is " << myMap["Alice"] << endl;

    // Check if a key exists in the map
    if (myMap.count("Dave") > 0) {
        cout << "Dave's age is " << myMap["Dave"] << endl;
    } else {
        cout << "Dave is not in the map." << endl;
    }

    // Iterate over the key-value pairs in the map
    for (auto& pair : myMap) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }

    return 0;
}
