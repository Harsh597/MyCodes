#include<iostream>
using namespace std;
string moveXtoend(string s)
{
    if(s.length()==0)
    return "";
    char ch=s[0];
    if(ch=='x')
    return moveXtoend(s.substr(1))+ch;
    return ch+moveXtoend(s.substr(1));
}
int main()
{
 string str="abfxxbhxxcdxcxcx";
 cout<<moveXtoend(str);
    return 0;
}