#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                //b=a+b-(a=b);
                arr[j] = arr[i] + arr[j] - (arr[i] = arr[j]);
            }
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