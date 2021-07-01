#include <stdio.h>
#include <conio.h>
void main()
{
    int a[25];
    int n, i;
    int count = 0;
    printf("\nProgram to find the number is repeated how many times in an array?");
    printf("\nEnter the 25 elements for the array\n");
    for (i = 0; i < 25; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nNow enter the element which you want to search in the array\n");
    scanf("%d", &n);
    for (i = 0; i < 25; i++)
    {
        if (a[i] == n)
            count++;
    }
    if (count == 0)
        printf("\nSorry!! This element is not present in the array");
    else
        printf("\n%d is present %d times in the array", n, count);
}