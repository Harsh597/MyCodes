#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    b = a + b - (a = b);
}
void dnfSort(int arr[], int n)
{
    int low, mid, high;
    low = mid = 0;
    high = n - 1;
    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 1, 0, 0, 1, 2, 2, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);
    int sorted_arr[n];
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    dnfSort(arr, n);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}