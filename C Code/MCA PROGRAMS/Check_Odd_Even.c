#include <stdio.h>
#include <conio.h>
void main()
{
    int num;
    printf("\nProgram to Check for Even-Odd\n");
    printf("\nEnter the number\n");
    scanf("%d", &num);
    if ((num % 2) == 0)
        printf("\n%d is even number", num);
    else
        printf("\n%d is odd number", num);
}