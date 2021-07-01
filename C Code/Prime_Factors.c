#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
void prime_factors(long int);
void prime_factorr(long int);
void factor(long int);

void main()
{
    long int num;

    printf("\nProgram to print the prime factors of the number using and without using recursion");
    printf("\n Enter the number\n");
    scanf("%ld", &num);
    prime_factors(num);
    prime_factorr(num);
    printf(" are the prime factors calculated  using recursion\n");
}
void prime_factors(long int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {

            if (check_prime(i))
            {
                printf("%d ", i);
            }
        }
    }
    printf(" are the prime factors calculated Without using recursion\n");
}
void prime_factorr(long int num)
{
    static int i = 2;

    if (i <= num)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
            num/= i;
        }
        else
            i++;
        prime_factorr(num);
    }
}
void factor(long int num)
{
}
