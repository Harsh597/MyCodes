#include <stdio.h>
#include <conio.h>
void main()
{
    int num, reverse = 0, temp, rem;
    printf("\nProgram to check whether the numbers is pallindrome or not\n");
    printf("Enter the number\n");
    scanf("%d", &num);
    temp = num;
    do
    {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp /= 10;
    } while (temp > 0);
    if (num == reverse)
        printf("\n%d is the pallindrome number", num);
    else
        printf("\n%d is not pallindrome number", num);
}