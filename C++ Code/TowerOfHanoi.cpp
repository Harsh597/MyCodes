#include <iostream>
using namespace std;
void towerofHanoi(int n, char src, char helper, char dest)
{
    if(n==0)
    return;
    towerofHanoi(n-1,src,dest,helper);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,helper,src,dest);
}
int main()
{
    towerofHanoi(4,'A','B','C');
    return 0;
}