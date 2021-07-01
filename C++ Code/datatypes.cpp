#include <iostream>
using namespace std;

int main()
{
    int a; //declaration
    float b;
    char c;
    bool d;
    short int si;
    long int li;

    a = 12; //initialization

    cout << "Size of int " << sizeof(a) << endl;

    cout << "Size of foat " << sizeof(b) << endl;

    cout << "Size of char " << sizeof(c) << endl;

    cout << "Size of bool " << sizeof(d) << endl;

    cout << "Size of short int " << sizeof(si) << endl;

    cout << "Size of long int " << sizeof(li) << endl;

    return 0;
}