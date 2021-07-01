#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
#define pi 3.14159
float mysin(float);
void main()//C question 5-j-f
{
  float n;
  printf("\nC function the evaluate the series of sin(x)");
  printf("\nEnter the value in degree\n");
  scanf("%f", &n);
  printf("\n The value of sin(%.1f) is %15.2f", n, mysin(n));
}
float mysin(float n)
{
  float x, result = 0.0;
  int sign = 1;
  x = n * (pi / (float)180);

  for (int i = 1, j = 0; j < 10; i = i + 2, j++)
  {
    result += sign * (powf(x, i) / fact(i));
    sign *= -1;
  }
  return result;
}