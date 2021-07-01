#include <iostream>
using namespace std;

int main()
{
    int row, col, i, j;
    cout << "Enter the no. of rows and columns\n";
    cin >> row ;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= row-i; j++)
        {
            cout<<" ";
           
        }
        for (j = 1; j <= i; j++)
        {
            cout<<" *";
           
        }
        
        cout << endl;
    }

    return 0;
}