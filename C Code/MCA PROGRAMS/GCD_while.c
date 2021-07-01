#include <stdio.h>
#include <conio.h>
void main()
{
    int num1, num2, gcd;
    printf("\nProgram to find the gcd of the two numbers");
    printf("\nEntet the first number\n");
    scanf("%d", &num1);
    printf("\nEntet the second number\n");
    scanf("%d", &num2);
    printf("\nThe GCD of %d and %d is  ", num1, num2);
    while (1)
    {
        if (num1 == 0)
        {
            gcd = num2;
            break;
        }
        else if (num2 == 0)
        {
            gcd = num1;
            break;
        }
        else if (num1 == num2)
        {
            gcd = num1;
            break;
        }
        else if (num1 > num2)
            num1 = num1 - num2;
        else
            num2 = num2 - num1;
    }
    printf("%d", gcd);
}