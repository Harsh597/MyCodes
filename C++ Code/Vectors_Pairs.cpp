#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool mycompare(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first < p2.first);
}
void reduce(int arr[], int size)
{

    vector<pair<int, int>> v;

    for (int i = 0; i < size; i++)
    {
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end(), mycompare);

    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }
}
int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    reduce(arr, n);
    for (auto ele : arr)
        cout << ele << endl;

    return 0;
}