#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
long int BinaryEqu(long int);
void main() //C Question  5-J-c
{
  long int n;
  printf("\nProgram to find the binary equivalent of the positve no. using recursion ");
  // printf("Enter the no.\n");
  // scanf("%ld", &n);
  for (int i = 0; i < 50; i++)
  {
    printf(" \n %d  = %ld ", i,BinaryEqu(i));
     
  }
  //printf("%ld",reverseno(BinaryEqu(n))) ;
}
long int BinaryEqu(long int n)
{
  if (n == 0)
    return 0;
  else
    return (n % 2) + 10 * BinaryEqu(n / 2);
}
// binary(int n)
// {
//     int y;

//     if (n > 0)
//     {
//         y = n;
//         n /= 2;

//         binary(n);
//         printf("%d",y%2);
//     }
// }