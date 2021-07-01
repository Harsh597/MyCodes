#include <iostream>
#include <math.h>
using namespace std;
int getbit(int n, int pos)
{
    // cout << "n = " << n << endl;
    return ((n & (1 << pos)) != 0);
}
void unique(int arr[], int n)
{
    int u1, u2;
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int pos = 0;
    while (pos < (log2(xorsum) + 1))
    {
        if (getbit(xorsum, pos) == 1)
            break;
         pos++;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getbit(arr[i], pos))
            newxor ^= arr[i];
    }
    cout << newxor << " " << (newxor ^ xorsum) << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    unique(arr, size);
    return 0;
}