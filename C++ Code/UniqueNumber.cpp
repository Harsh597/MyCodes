#include <iostream>
#include <algorithm>
using namespace std;
int xorsum(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 7, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << xorsum(arr, size);
    //cout << (xorsum(arr, size) ^ 7);

    return 0;
}