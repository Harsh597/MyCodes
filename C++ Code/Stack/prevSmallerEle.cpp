#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void prevSmaller(int arr[],int n)
{
    stack<int> st;
    int pse[n];
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() &&  arr[i]<=st.top())
            st.pop();
        
        if(!st.empty())
            pse[i]=st.top();
        else
            pse[i]=-1;
        
        st.push(arr[i]);
    }
    cout<<"ans"<<endl;
    for(int e:pse)
        cout<<e<<" ";
}
int main()
{
    int arr[]={4,12,5,3,1,2,5,4,1,2,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    prevSmaller(arr,n);
    return 0;
}