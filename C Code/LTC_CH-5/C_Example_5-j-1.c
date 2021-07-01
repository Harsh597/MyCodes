#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "MyLibrary.c"

void main()
{

    long int num;
    printf("Program to find the sum of the digit of a any digit integer without recursion\n");
    printf("\nEnter the any digit number\n");
    scanf("%ld", &num);
    printf("\nSum of the digits of %ld is %d", num, sum_of_digit(num));
}

