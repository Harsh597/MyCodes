#include <stdio.h>
#include <conio.h>
#include <math.h>
#include"MyLibrary.c"
void main()
{
   int num, sum, temp = 0;
   printf("Program to reverse a five digit number\n\n");
   printf("\nEnter any  digit number\n");
   scanf("%d", &num);
   for (int i = 1, j = no_of_digits(num)-1 ; i <= no_of_digits(num); i++, j--)
   {
      sum = (num % (int)powf(10, i)) / pow(10, i - 1);
      temp += sum * powf(10, j);
   }

   printf("\nReversed NO-- of %d ", temp);
}