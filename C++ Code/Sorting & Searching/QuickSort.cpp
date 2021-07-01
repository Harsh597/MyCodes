#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    *b = *a + *b - (*a = *b);
}
int partition(int arr[], int l, int r)
{
    int pivot_ele = arr[r];
    int pindex = l - 1;
    for (int i = l; i < r; i++)
    {
        if (arr[i] < pivot_ele)
        {
            pindex++;
            swap(&arr[pindex], &arr[i]);
        }
    }
    swap(&arr[pindex + 1], &arr[r]);

    return (pindex + 1);
}
void QuickSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int pivot_ele_idx = partition(arr, l, r);
    QuickSort(arr, l, pivot_ele_idx - 1);
    QuickSort(arr, pivot_ele_idx + 1, r);
}
int main()
{
    int arr[] = {2, 9, 4, 8, 12, 65, 0, -3};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    QuickSort(arr, 0, n - 1);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}