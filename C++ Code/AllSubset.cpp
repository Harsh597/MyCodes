#include <iostream>
using namespace std;
void subset(int arr[], int n)
{
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    subset(arr, size);
    return 0;
}