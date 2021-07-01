#include<stdio.h>
#include<conio.h>
void circular_shift(int *, int *,int*);
void main()
{
    int x=5,y=8,z=10;
    printf("Program to circularly shift 3 numbers using function\n");
    printf("Value of the variables before circular shift is \n");
    printf("x=%d\t y=%d\t z=%d",x,y,z);
    circular_shift(&x,&y,&z);
    printf("\nValue of the variables after circular shift is \n");
    printf("x=%d\t y=%d\t z=%d",x,y,z);
}
void circular_shift(int *a,int *b,int *c)
{
  // b=a+b-(a=b);
   *a=*c+*a-(*c=*a);
   *b=*c+*b-(*c=*b);
}