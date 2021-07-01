#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (arr[j] > curr && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
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