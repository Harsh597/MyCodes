#include <stdio.h>
#include <conio.h>
#include "C:\Users\harsh\OneDrive\Documents\C Code\MyLibrary.c"
void bubble_sort(int[], int);

void main()
{
    int a[] = {23, 10, 16, 11, 20, 13, 38, 67, 28};

    printf("\nProgram for the Bubble s algo");
    printf("\nArray before sorting\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    bubble_sort(a, 9);
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
        printf("\n%d iteration :  ", i + 1);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
    }
}