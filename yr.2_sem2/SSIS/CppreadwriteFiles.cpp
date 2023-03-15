#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

 fstream myFile;

 myFile.open("saldina.txt", ios::in);
 if (myFile.is_open()){
    string line;
    while (getline(myFile, line)) {
        cout << line << endl;
    }
    myFile.close();
 }


/*  myFile.open("saldina.txt", ios::out); // write mode
 if (myFile.is_open()) {
    myFile << "Hello\n";
    myFile << "This is second line\n";
    myFile.close();
 }

 myFile.open("saldina.txt", ios::app); // append mode
 if (myFile.is_open()) {
    myFile << "Hello2\n";
    myFile << "This is third line\n";
    myFile.close();
 }
 */
    return 0;
}