// C program for insertion sort
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// heap sort
// Function to swap the the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// quick sort
void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

// merge sort
//  Merges two subarrays of arr[].
//  First subarray is arr[l..m]
//  Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    clock_t t;
    double time_taken;
    int n;
    printf("Enter the size of array \n");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    // int arr[] = {12, 11, 13, 5, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    t = clock();
    insertionSort(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\ntime taken using Insertion Sort %lf milli seconds", time_taken*1000);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    t = clock();
    // mergeSort(arr, 0, arr_size - 1);

    mergeSort(arr, 0, n - 1);

    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\ntime taken using Merge Sort %lf milli seconds", time_taken*1000);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    t = clock();
    // quicksort(number, 0, count - 1);
    quicksort(arr, 0, n - 1);

    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\ntime taken using Quick Sort %lf milli milli seconds", time_taken*1000);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    t = clock();
    heapSort(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\ntime taken using Heap Sort %lf milli milli seconds", time_taken*1000);

    // printArray(arr, n);

    return 0;
}
