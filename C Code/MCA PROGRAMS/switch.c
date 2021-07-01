#include <stdio.h>
#include <conio.h>
void main()
{
    int a, b;
    char opr;
    printf("\nProgram to do all operations on the two numbers\n");
    printf("\n enter which operation you want\n");
        
    scanf("%c", &opr);
    printf("\nEnter the two numbers\n");
    scanf("%d%d", &a, &b);

    switch (opr)
    {
    case '+':
        printf("\nThe sum of two numbers is %d", a + b);
        break;
    case '-':
        printf("\nThe difference of two numbers is %d", a - b);
        break;
    case '/':
        printf("\nThe division of two numbers is %d", a / b);
        break;
    case '*':
        printf("\nThe multiplication of two numbers is %d", a * b);
        break;

    default:
        printf("\nThis operation is invalid");
    }
}