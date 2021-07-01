#include <iostream>
using namespace std;
void CountSort(int arr[], int n, int sorted_arr[])
{
    int max_no = arr[0];
    for (int i = 1; i < n; i++)
        max_no = max(max_no, arr[i]);

    int count_arr[max_no + 1]{};
    int mod_count_arr[max_no + 1]{};
    for (int i = 0; i < n; i++)
        ++count_arr[arr[i]];

    mod_count_arr[0] = count_arr[0];

    for (int i = 1; i < n; i++)
        count_arr[i] +=count_arr[i - 1];

    for (int i = n - 1; i >= 0; i--)
        sorted_arr[--(count_arr[arr[i]])] = arr[i];
    
     
}
int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    int n = sizeof(arr) / sizeof(arr[0]);
    int sorted_arr[n];
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    CountSort(arr, n, sorted_arr);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << sorted_arr[i] << " ";

    return 0;
}