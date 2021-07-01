#include <iostream>
using namespace std;
//Maximum SubArray Sum Problem  with Cumulative Sum Approach
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int csum[n]; //cumulative sum array;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    csum[0] = arr[0];
    int maxsum = csum[0];
    for (int i = 1; i < n; i++)
    {
        //int maxsum = 0;
        for (int j = 0; j < i; j++)
        {
            csum[i] = csum[i - 1] + arr[i];
            maxsum = max(maxsum, max(csum[i], csum[i] - csum[j]));
        }
    }

    cout << maxsum;

    return 0;
}