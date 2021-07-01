#include <iostream>
using namespace std;
void getvalue(int arr[], int n)
{
    cout << "\nEnter the " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
}

void maxTill_I(int arr[], int n)
{
    int mx=arr[0];

    for ( int i = 0; i < n; i++)
    {
        mx= max(mx,arr[i]);
        cout<<mx<<" ";
    }
    

}
int main()
{
    int n;
    cout << "How many elements you want in the array" << endl;
    cin >> n;
    int arr[n];
    getvalue(arr, n);

    maxTill_I(arr,n);

    return 0;
}