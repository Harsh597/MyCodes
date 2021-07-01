#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int top_ele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top_ele);
}
void reverse(stack<int> &st)
{
    if (st.empty())
        return;
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}
void display(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << "\n";
        st.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    display(st);
    reverse(st);
    cout<<endl;
    display(st);

    return 0;
}
