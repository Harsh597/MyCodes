#include <stdio.h>
void main()
{
    int num;
    long fact = 1;
    int i;
    printf("\nProgram to find the factorial of the number\n");
    printf("\nEnter the number\n");
    scanf("%d", &num);
    for (i = num; i > 0; i--)
    {
        fact *= i;
    }
    printf("factorial of %d!  is %ld", num, fact);
}