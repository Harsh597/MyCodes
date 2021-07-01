#include <iostream>
using namespace std;
int main()
{
    int i, j, n;
    cout << "Enter the no. of rows" << endl;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i + 1; j++)
            cout <<" "<<j;
        cout << endl;
    }

    return 0;
}