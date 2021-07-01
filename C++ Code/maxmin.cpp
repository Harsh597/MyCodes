#include <iostream>
#include <limits>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxNo = INT32_MIN;
    int minNo = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        // if (arr[i] > maxNo)
        //     maxNo = arr[i];
        maxNo = max(arr[i], maxNo);
        // if (arr[i] < minNo)
        //     minNo = arr[i];
        minNo = min(arr[i], minNo);
    }
    cout << "Max : " << maxNo << endl;
    cout << "Min : " << minNo << endl;

    return 0;
}