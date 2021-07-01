#include <iostream>
using namespace std;
#define n 100
class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "\nStack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "\nStack Underflow" << endl;
            return;
        }
        cout << arr[top] << " is deleted" << endl;
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "\nStack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
    void display()
    {
        int temp = top;
        while (temp != -1)
        {
            cout << arr[temp] << "\n";
            temp--;
        }
        cout << endl;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    cout << st.peek() << endl;
    st.pop();
    st.display();

    cout << st.peek() << endl;
    st.pop();
    st.display();

    st.pop();
    st.display();

    st.pop();
    st.display();

    cout << st.empty() << endl;
    st.display();
    st.pop();
    st.display();
    cout << st.empty() << endl;

    return 0;
}