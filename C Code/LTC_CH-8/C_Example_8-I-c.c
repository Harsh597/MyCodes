#include <stdio.h> //(c) Find the smallest number in an array using pointers.
#include <conio.h>
int smallest(int*,int);

void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    printf("\nProgram to find the smallest number in the array using pointers\n");
    printf("\nArray elements are\n");
    int length = sizeof(a) / sizeof(a[0]);
    
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nThe smallest number in the array is %d",smallest(a,length))  ;
}
int smallest (int *ptr,int len)
{
    int min=*ptr;
    for (int i = 0; i < len; i++)
    {
      if(*(ptr +i)<min) 
      {
          min=*(ptr +i);
      }

    }
      return min;

    
}