#include <stdio.h>
#include <conio.h>
void main()
{
    int num, rem, reverse = 0, temp;
    printf("\nProgram to find the reverse of the number\n");
    printf("Enter the number\n");
    scanf("%d", &num);
    temp = num;
    while (temp > 0)
    {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp /= 10;
    }

    printf("\nThe reverse of the %d is %d", num, reverse);
}