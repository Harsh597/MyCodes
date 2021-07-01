#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
void insertion_sort(int[], int);
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    int temp, i, j;

    printf("\nProgram for the insertion sort algo");
    printf("\nArray before sorting\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    insertion_sort(a, 9);
}

void insertion_sort(int a[], int n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
        printf("\n%d iteration :  ", i + 1);
        for (int l = 0; l < n; l++)
            printf("%d ", a[l]);
    }
}