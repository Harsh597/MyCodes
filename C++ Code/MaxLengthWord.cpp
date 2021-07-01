#include <iostream>
using namespace std;
//largest word in the sentence
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];

    cin.getline(arr, n);

    int currlen = 0, maxlen = 0;
    int st = 0;
    int i = 0;
    while (1)
    {

        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currlen > maxlen)
            {
                maxlen = currlen;
                st = i-maxlen;
            }
            currlen = 0;
        }
        else
        {
            currlen++;
        }

        if (arr[i] == '\0')
            break;
        i++;
    }
    cout << maxlen << endl;
    for (int i = 0; i < maxlen; i++)
    {
        cout << arr[i + st];
    }

    return 0;
}