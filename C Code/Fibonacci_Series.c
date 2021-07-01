#include <stdio.h>
#include <conio.h>
void fibonacci(int);

void main() //question of Let us C 5-j-c(recursion)
{
    int n;
    printf("\nProgram to print the fibonacci series using recursion");
    printf("\nEnter the number of terms you want in the series\n");
    scanf("%d", &n);
    fibonacci(n);
}

void fibonacci(int n)
{
    static int i = 2;
    static int a = 0;
    static int b = 1;
    int c;
    if (n == 1)
        printf(" 1 ");

    if (n >= 2 && i == 2)
        printf(" 1 ");

    if (i <= n)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
        i++;

        fibonacci(n);
    }
}