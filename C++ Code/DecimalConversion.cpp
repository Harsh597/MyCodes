#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int binaryToDecimal(int n)
{
    int rem, base = 1;
    int dec = 0;
    while (n > 0)
    {
        rem = n % 10;
        dec += rem * base;
        base *= 2;
        n /= 10;
    }

    return dec;
}
int octalToDecimal(int n)
{
    int rem, base = 1;
    int dec = 0;
    while (n > 0)
    {
        rem = n % 10;
        dec += rem * base;
        base *= 8;
        n /= 10;
    }

    return dec;
}
int hexadecimalToDecimal(string n)
{
    int size = n.size();
    int base = 1;
    int dec = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            dec += base * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            dec += base * (n[i] - 'A' + 10);
        }

        base *= 16;
    }

    return dec;
}
int decimalToBinary(int n)
{
    int rem, bin = 0;
    int ten = 1;
    while (n > 0)
    {
        rem = n % 2;
        bin += ten * rem;
        ten *= 10;

        n /= 2;
    }
    return bin;
}
int decimalToOctal(int n)
{
    int rem, oct = 0;
    int ten = 1;
    while (n > 0)
    {
        rem = n % 8;
        oct += ten * rem;
        ten *= 10;

        n /= 8;
    }
    return oct;
}

string decimalToHexadecimal(int n)
{
    int rem;
    string hex = "";

    if (n == 0)
        return "";
    else
    {

        hex += decimalToHexadecimal(n / 16);

        rem = n % 16;
        if (rem <= 9)
        {
            //rem *= ten;
            hex += to_string(rem);
        }
        else
        {
            //rem *= ten;

            hex.push_back((char)(65 + rem - 10));
        }
        //n /= 16;
    }

    return hex;
}
int main()
{
    int n;
    //string n;

    cout << "Enter decimal number" << endl;
    cin >> n;

    // cin >> n;
    // cout << binaryToDecimal(n) << endl;
    //cout << octalToDecimal(n) << endl;
    //cout << decimalToOctal(n) << endl;
    cout << decimalToHexadecimal(n) << endl;

    return 0;
}