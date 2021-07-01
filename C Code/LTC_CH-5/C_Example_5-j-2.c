#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
int sum_of_digitr(long int);

void main()
{
    long int num;
    printf("Program to find the sum of the any digit number \n");
    printf("Enter the number\n");
    scanf("%ld", &num);
    printf("\nsum of the digits is %d using recursion", sum_of_digitr(num));
    printf("\nsum of the digits is %d without using recursion", sum_of_digits(num));
}
int sum_of_digitr(long int num)
{
    int sum = 0;

    if (num <= 10)
        return num;
    sum = num % 10;
    return (sum + sum_of_digitr(num / 10));
}