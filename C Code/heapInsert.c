#include <stdio.h>
#include <math.h>
#define SIZE 20
int arr[SIZE];
void displayHeap(int n)
{
    int i = 0; //lc :left child, rc : right child
    printf("\nRoot ");
    while (i < n)
    {
        printf("Node : %d\n", arr[i]);
        if ((2 * i + 1) < n)
        {
            printf("Left Child : %d  ", arr[2 * i + 1]);
        }
        else
        {
            printf("Left Child : -1  ");
        }

        if ((2 * i + 2) < n)
        {
            printf("Right Child : %d", arr[2 * i + 2]);
        }
        else
        {
            printf("Right Child : -1  ");
        }
        i++;
        printf("\n\n");
    }
}
void insertHeap(int item, int n)
{
    int j = n, temp;
    int i = floor((n - 1) / 2);
    arr[n] = item;

    while (i >= 0 && arr[i] > item)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j = i;
        i = floor((i - 1) / 2);
    }

}
int main()
{
    int n;
    printf("\nEnter the no. of elements to be inserted\n");
    scanf("%d", &n);
    printf("\nNow, Enter all the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        insertHeap(arr[i], i);
    }

    displayHeap(n);
    return 0;
}