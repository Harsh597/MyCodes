#include <iostream>
using namespace std;
bool ispowerof2(int n) //(n & n-1) has same bits as n except the rightmost set bit
{
    return (n && !(n & n - 1));
}
int main()
{
    cout << ispowerof2(32) << endl;

    return 0;
}