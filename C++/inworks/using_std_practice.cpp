#include<iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
// using namespace std;

namespace namespace1{
    int age = 25;
    string name = "NoriAnne";
}
namespace namespace2{
    int age = 30;
}

int main()
{
    std::cout << namespace1::age << endl;
    cout << namespace1::name << endl;
    cout << namespace2::age << endl;


return 0;
}