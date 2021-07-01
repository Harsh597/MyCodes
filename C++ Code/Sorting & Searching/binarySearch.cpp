#include <iostream>
using namespace std;
void sort(int arr[], int n)//bubble sort
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                //b=a+b-(a=b)
                // arr[j] = arr[i] + arr[j] - (arr[i] = arr[j]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}
int binarySearch(int arr[], int n, int key)
{
    int l = 0;
    int h = n-1;
    while (l <= h)
    {
        int m = (l + h) / 2;

        if (key == arr[m])
            return m;
        else if (key < arr[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {4, 7, 8, 1, 41, 89,2, 0};
    int key;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "n : " << n << endl;

    sort(arr, n);
    cout << "Array elements" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nEnter the element you want to search" << endl;
    cin >> key;
    cout << binarySearch(arr, n, key) << endl;
    return 0;
}