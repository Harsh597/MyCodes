#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s1="3245";
    sort(s1.begin(),s1.end(),greater<int>());
    cout<<s1;
    return 0;
}