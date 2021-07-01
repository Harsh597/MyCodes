#include <stdio.h>
void main()
{
    int num, i = 2;
    printf("\nProgram to print the prime factors of the number\n");
    printf("\nEnter the number\n");
    scanf("%d", &num);
    printf("\nPrime factorisation of %d is \n", num);

    while (num != 1)
    {
        if (num % i == 0)
        {
            printf("\n%d", i);

            num /= i;
        }
        else
            i++;
    }
}