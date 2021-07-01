#include <iostream>
using namespace std;
int kadanes(int arr[], int n)
{
    int currsum = 0;
    int maxsum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
            currsum = 0;
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int wrapsum;
    int nonwrapsum;
    int maxsum = INT32_MIN;
    int totalsum = 0;
    int sign = -1;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    nonwrapsum = kadanes(arr, n);

    for (int i = 0; i < n; i++)
    {
        maxsum = max(arr[i], maxsum);
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + kadanes(arr, n);
    int ans = max(wrapsum, nonwrapsum);
    if (ans == 0)
        cout << maxsum << endl;
    else
        cout << ans << endl;

    return 0;
}