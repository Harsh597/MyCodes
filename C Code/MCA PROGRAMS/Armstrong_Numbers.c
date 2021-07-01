#include <stdio.h>
#include <conio.h>
void main()
{
  int num, rem, sum = 0, temp;
  printf("\nProgram to check for Armstrong Number\n");
  printf("Enter the number\n");
  scanf("%d", &num);
  temp = num;
  do
  {
    rem = temp % 10;
    sum = sum + (rem * rem * rem);
    temp /= 10;
  } while (temp > 0);

  if (num == sum)
  {
    printf("\n%d is  Armstrong Number", num);
  }
  else
    printf("\n%d is not  Armstrong Number", num);
}