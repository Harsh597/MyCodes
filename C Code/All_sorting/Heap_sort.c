#include <stdio.h>
#include "MyLibrary.c"
void heapify(int a[], int n, int i)
{
    int largest = i; //   find the  largest among root,left child and right child
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i) // Swap and continue heapifying if root is not largest
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void heap_sort(int a[], int n)
{
    //Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    //Heap sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        //Heapify root element to get highest element at root again
        heapify(a, i, 0);
    }
}
void print_array(int a[], int length)
{
    printf("\nArray after sorting\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}
void main()
{
    int a[] = {12, 78, 3, 56, 1, 6, 38, 67, 8};
    int length = sizeof(a) / sizeof(a[0]);
    printf("\nProgram to implement the heap sort\n");
    printf("\nArray before sorting\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    heap_sort(a, length);
    print_array(a, length);
}