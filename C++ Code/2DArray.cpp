#include <iostream>
using namespace std;
int main()
{
    //2D array declaration
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    return 0;
}