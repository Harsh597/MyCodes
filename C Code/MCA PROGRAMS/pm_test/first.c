#include <stdio.h>
void main()
{
    int arr[20];
    int n;
    printf("\nprogramt to count number of 1s in n elements in an array\n");
    printf("Enter the number of elements you want in the array(max 20)\n");
    scanf("%d", &n);
    printf("\nEnter the %d elements \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray contains %d 1s ", count_one(arr, n));
}
int count_one(int arr[], int n)
{
    int i, num, count = 0, rem;

    for (i = 0; i < n; i++)
    {
        num = arr[i];
        printf("\n num = %d", num);
        while (num > 0)
        {
            rem = num % 10;
            num /= 10;

            printf("\ndigit = %d", rem);
            if (rem == 1)
                count++;
        }
    }
    return count;
}