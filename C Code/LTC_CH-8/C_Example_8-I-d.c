//  Write a program which performs the following tasks:
// − initialize an integer array of 10 elements in main( )
// − pass the entire array to a function modify( )
// − in modify( ) multiply each element of array by 3
// − return the control to main( ) and print the new array
// elements in main( )
#include <stdio.h>
#include <conio.h>
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8, 34};
    printf("\nProgram to modify elements of the array\n");
    printf("\nArray elements are before modification\n");
    int length = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    modify(a, length);
    printf("\nArray elements after  modification\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}
void modify(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] *= 3;
    }
}