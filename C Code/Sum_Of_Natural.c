#include <stdio.h>
#include <conio.h>
long int sum_of_natural(int);
void main()
{
    int n;
    printf("Program to print the sum of the natural number using recursion\n");
    printf("Enter the no of the terms you want\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf(" %d",i);
    }
    
    printf("\nSum of the %d natural number is %ld", n, sum_of_natural(n));
}
long int sum_of_natural
(int n)
{
      
    if (n == 1)
        return 1;
    else
        return (n + sum_of_natural(n - 1));
}