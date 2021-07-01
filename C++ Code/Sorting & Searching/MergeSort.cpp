#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int h)
{
    int len1 = m - l + 1;
    int len2 = h - m;
    int a[len1];
    int b[len2];
    int i, j, k=l;
    for (i = 0; i < len1; i++)
    {
        a[i] = arr[l + i];
    }
    for (j = 0; j < len2; j++)
    {
        b[j] = arr[m + 1 + j];
    }
    i = j = 0;
    while (i < len1 && j < len2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < len1)
        arr[k++] = a[i++];

    while (j < len2)
        arr[k++] = b[j++];
}
void Mergesort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int m = (l + h) / 2;

    Mergesort(arr, l, m);
    Mergesort(arr, m + 1, h);

    merge(arr, l, m, h);
}
int main()
{
    int arr[] = {2, 9, 4, 8, 12, 65, 0, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    Mergesort(arr, 0, n - 1);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}