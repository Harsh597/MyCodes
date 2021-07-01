#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
void selection_sort(int[], int);
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};

    printf("\nProgram for the selection sort algo");
    printf("\nArray before sorting\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    selection_sort(a, 9);
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                swap(&a[j], &a[i]);
        }

        printf("\n%d iteration :  ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
    }
}