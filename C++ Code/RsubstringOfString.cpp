#include <iostream>
using namespace std;
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    subseq(s.substr(1),ans );
    subseq(s.substr(1),ans+s[0]);
}
int main()
{
    subseq("ABC","");
    return 0;
}