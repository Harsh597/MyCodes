#include <stdio.h>
void displayHeap(int arr[], int n)
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
void insertHeap(int arr[], int n, int item)
{

    int j = n, i = (n / 2) - 1, temp;
    arr[n] = item;

    while (i >= 0 && arr[i] < item)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j = i;
        i = i >> 1;
    }
}
int main()
{
    // int arr[] = {90, 60, 80, 30, 10, 5, 7, 15};
    int item, n,i,temp;
    // int n = sizeof(arr) / sizeof(arr[0]);
    int *arr;
    printf("Enter the number of elements you want to add\n");
    scanf("%d", &n);
    printf("value of n %d ",n);
    printf("\nEnter elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        arr[i]=temp;

    }
     for ( i = 0; i < n; i++)
    {
        insertHeap(arr, i, arr[i]);
    }
    displayHeap(arr, n);
    // printf("\nEnter the element to be inserted\n");
    // scanf("%d", &item);
    // displayHeap(arr, n + 1);
    return 0;
}