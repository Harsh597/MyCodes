#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    cout << "Enter the no. of rows" << endl;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (((i + j) & 1) == 0)
                cout << " 1";
            else
                cout << " 0";
        }
        cout << endl;
    }

    return 0;
}