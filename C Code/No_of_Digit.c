#include <stdio.h>
#include <math.h>

void main()
{
    long unsigned int num;
  int i = 0;
  printf("***********Program to Count the no. of the digits in the Entered Number***********\n");
  printf("\nEnter any number\n");
  scanf("%lud",&num);
  while ((num / powf(10, i)) > 1 || (num / powf(10, i) )< -1 )
  {
    i++;
  }
  
  printf("\nYou have entered a %d digit number", i);
}