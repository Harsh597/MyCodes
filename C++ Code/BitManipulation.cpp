#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearbit(int n, int pos)
{
    return (n & ~(1 << pos));
}
int updatebit(int n, int pos, int value)
{
    if (value)
        return setbit(n, pos);
    else
        return clearbit(n, pos);
}
int main()
{
    // cout << getbit(15, 2);
    // cout << setbit(5, 1);
  //  cout << clearbit(5, 2);
  cout<<updatebit(10,0,1);
    return 0;
}