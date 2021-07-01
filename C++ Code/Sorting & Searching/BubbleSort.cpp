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
                 arr[j] = arr[j+1] + arr[j] - (arr[j+1] = arr[j]);
               
            }
    }
}

int main()
{
    int arr[] = {2, 9, 4, 8, 12, 65, 0, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sort(arr, n);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}