#include <iostream>
using namespace std;
int numberOfOnes(int n) //(n & n-1) has same bits as n except the rightmost set bit
{
    int count = 0;
    while (n)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}
int main()
{
    cout << numberOfOnes(31);
    return 0;
}