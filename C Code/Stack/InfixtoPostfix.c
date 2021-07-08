#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int capacity;
    char *arr;
};
typedef struct Stack stack;
stack st;
int isOperator(char ch)
{
    if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '%')
        return 1;
    else
        return 0;
}
void push(char ch)
{
    if (st.top == st.capacity - 1)
    {
        printf("Expression is too big to evaluate\n");
        exit(0);
    }
    st.top++;
    st.arr[st.top] = ch;
}
char pop()
{
    st.top--;
    return st.arr[st.top + 1];
}
char peek()
{
    return st.arr[st.top];
}
int isEmpty()
{
    return (st.top == -1);
}
int prec(char ch)
{
    if (ch == '+' || ch == '-')
        return 0;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 1;

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
            printf("\n%c", st.arr[temp--]);
    }
    printf("@\n");
}
int isOperand(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57))
        return 1;
    else
        return 0;
}
void InfixtoPostfix(char *expression, int len)
{
    st.capacity = len;
    st.top = -1;
    st.arr = (char *)malloc(st.capacity * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        if (isOperand(expression[i]))
            printf("%c", expression[i]);
        else if (isOperator(expression[i]) || expression[i] == '(')
        {
            while (prec(expression[i]) <= prec(peek()) && peek() != '(' && !isEmpty())
                printf("%c", pop());
            push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (peek() != '(')
                printf("%c", pop());
            pop();
        }
        
    }
    while (!isEmpty())
        printf("%c", pop());

    free(st.arr);
}

int main()
{
    char expression[50];
    int len;
    printf("\nINFIX to POSTFIX Conversion\n");
    printf("\n Enter the expresiion\n ");
    scanf("%s", expression);
    len = strlen(expression);
    printf(" Postifix Equivalent : ");
    InfixtoPostfix(expression, len);

    return 0;
}