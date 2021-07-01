#include <iostream>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int currsum = 0;
    int st = 0;
    int en = 0;
    for (int en = 0; en < n; en++)
    {
        currsum += arr[en];
        while (currsum > sum)
        {
            currsum -= arr[st];
            st++;
        }
        if (st > en)
        {
            cout << "-1";
            break;
        }
        if (currsum == sum)
        {

            cout << st << " " << en << endl;
            break;
        }
    }

    return 0;
}