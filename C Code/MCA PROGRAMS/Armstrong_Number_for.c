#include <stdio.h>
#include <conio.h>
void main()
{
    int num, rem, sum = 0, temp;
    printf("\nProgram to check for Armstrong Number\n");
    printf("Enter the number\n");
    scanf("%d", &num);
    for (temp = num; temp > 0; temp /= 10)
    {
        rem = temp % 10;
        sum = sum + (rem * rem * rem);
    }

    if (num == sum)
    {
        printf("\n%d is  Armstrong Number", num);
    }
    else
        printf("\n%d is not  Armstrong Number", num);
}