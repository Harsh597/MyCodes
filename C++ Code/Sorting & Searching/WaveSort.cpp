#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    b = a + b - (a = b);
}
void waveSorting(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
            swap(arr[i], arr[i - 1]);
        if (arr[i] > arr[i + 1] && i <= n - 2)
            swap(arr[i], arr[i + 1]);
    }
}
int main()
{
    int arr[] = { 1, 3, 4, 7, 5, 6, 2 };

    int n = sizeof(arr) / sizeof(arr[0]);
    int sorted_arr[n];
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    waveSorting(arr, n);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}