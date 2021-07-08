#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *arr;
};
typedef struct Stack stack;
stack st;
void createStack()
{
    int capacity = 10;
    char ch;
    st.top = -1;
    printf("Default Size of Stack is :10. Do you want to change it?y/n ");
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter the new capacity\n");
        scanf("%d", &capacity);
    }
    st.capacity = capacity;
    st.arr = (int *)malloc(st.capacity * sizeof(int));
}
void push()
{
    int item;
    if (st.top == st.capacity - 1)
        printf("\nStack Overflow\n");
    else
    {
        printf("Enter the element\n");
        scanf("%d", &item);
        st.top++;
        st.arr[st.top] = item;
    }
}
void pop()
{
    if (st.top == -1)
        printf("\nStack Underflow");
    else
    {
        printf("%d is deleted\n", st.arr[st.top]);
        st.top--;
    }
}
void display()
{
    int temp = st.top;
    if (temp == -1)
        printf("\nEmpty Stack\n");
    else
    {
        printf("\nStack :");
        while (temp != -1)
            printf("\n%d", st.arr[temp--]);
    }
}
int main()
{
    int choice;

    printf("Stack Operations\n");
    createStack();
    do
    {
        printf("\n1)Push\t2)Pop\t3)Display\t4)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            free(st.arr);
            exit(0);
        }
    } while (choice != 4);

    return 0;
}
