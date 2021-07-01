#include <stdio.h>
void main()
{
    int dividend, divisor;
    printf("\nProgram to find the quotient and Reminder\n");
    printf("Enter the Dividend\n");
    scanf("%d", &dividend);
    printf("\nNow enter the Divisor\n");
    scanf("%d", &divisor);

    printf("\nQuotient = %d\n Remainder = %d", dividend / divisor, dividend % divisor);
}