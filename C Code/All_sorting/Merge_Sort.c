#include <stdio.h>
#include <conio.h>
void print_array(int[], int);
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    int length = sizeof(a) / sizeof(a[0]);
    printf("\nProgram for the Merge sort algo");
    printf("\nArray before sorting\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    merge_sort(a, 0, length - 1);
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
void merge_sort(int a[], int left, int right)
{
    int mid;
    if (left >= right)
        return;
    mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}
void merge(int a[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int left_array[len1];
    int right_array[len2];
    for (int i = 0; i < len1; i++)
    {
        left_array[i] = a[left + i];
    }
    for (int j = 0; j < len2; j++)
    {
        right_array[j] = a[mid + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (i < len1 && j < len2)
    {
        if (left_array[i] <= right_array[j])
        {
            a[k] = left_array[i];
            i++;
        }
        else
        {
            a[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < len1)
    {
        a[k] = left_array[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        a[k] = right_array[j];
        j++;
        k++;
    }
}