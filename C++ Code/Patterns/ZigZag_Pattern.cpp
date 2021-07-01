#include <iostream>
using namespace std;
int main()
{
    int r, c, n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    for (r = 1; r <= 3; r++)
    {
        for (c = 1; c <= n; c++)
        {
            if (((r + c) % 4 == 0) || ((r == 2) && (c % 4 == 0)))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}