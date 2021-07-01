#include<iostream>
using namespace std;
string removeDup(string s)
{
    if(s.length()==0)
    return "";

    char ch=s[0];
    if(ch==removeDup(s.substr(1))[0])
    return removeDup(s.substr(1));

    return ch +removeDup(s.substr(1));
}
int main()
{
    cout<<removeDup("aaaaabbbcccedddd");
    return 0;
}