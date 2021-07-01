#include <iostream>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int ascii_ch=ch;
    subseq(s.substr(1), ans);
    subseq(s.substr(1), ans + s[0]);
    subseq(s.substr(1), (ans + to_string(ascii_ch)));
}
int main()
{
    subseq("AB","");
    return 0;
}