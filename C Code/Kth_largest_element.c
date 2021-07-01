#include <stdio.h> //Example of Quick Sort----->Find the kth largest element from the array
#include <conio.h> //Youtube channel Great Learning
#include "MyLibrary.c"
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
int quick(int a[], int desired, int beg, int end)
{
    int p = partition(a, beg, end);
    if (p == desired)
        return a[p];
    else if (desired < p)
        return quick(a, desired, beg, p - 1);
    else
        return quick(a, desired, p + 1, end);
}
int find_kth_largest(int a[], int k, int len)
{
    int desired = len - k;
    return quick(a, desired, 0, len - 1);
}
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    int length = sizeof(a) / sizeof(a[0]);
    int k = 4;
    printf("%d is the %d largest element in the array", find_kth_largest(a, k, length),k);
}