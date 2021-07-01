#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
void print_array(int [],int );
void quick_sort(int [],int,int);
int partition(int [],int,int);
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    int length = sizeof(a)/ sizeof(a[0]);
    printf("\nProgram for the selection sort algo");
    printf("\nArray before sorting\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    quick_sort(a, 0, length - 1);
    print_array(a, length);
}

void print_array(int a[], int length)
{
    printf("\nArray after sorting\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}
void quick_sort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int p_index = partition(a, beg, end);
        quick_sort(a, beg, p_index - 1);
        quick_sort(a, p_index + 1, end);
    }
}
int partition(int a[], int beg, int end)
{
    int pivot = a[end];
    int p_index = beg - 1;
    for (int i = beg; i < end; i++)
    {
        if (a[i] < pivot)
        {
            p_index++;
            swap(&a[i], &a[p_index]);
        }
    }
    swap(&a[p_index + 1], &a[end]);
    return p_index + 1;
}