#include <stdio.h>
#include <conio.h>
void main()
{
    int num, reverse = 0, temp, rem;
    printf("\nProgram to check whether the numbers is pallindrome or not\n");
    printf("Enter the number\n");
    scanf("%d", &num);
    for (temp = num; temp > 0; temp /= 10)
    {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
    }
    if (num == reverse)
        printf("\n%d is the pallindrom number", num);
    else
        printf("\n%d is not pallindrom number", num);
}