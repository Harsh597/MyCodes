#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "MyLibrary.c"

void main()
{
    int r, c, row;
    printf("\nProgram to find the norm of the matrix");
    printf("\nEnter the no. of rows you want int the matrix\n");
    scanf("%d", &r);
    printf("\nEnter the no. of rows you want int the matrix\n");
    scanf("%d", &c);
    int a[r][c];
    printf("\nThis is the random matrix element");
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {

            printf("%5d", (a[i][j] = (a[i][j]) % 9));
        }
    }
    printf("\nEnter which row you want to shift ");
    scanf("%d", &row);
    shift_array(a[row - 1], c);
    printf("\nmatrix after left shift row elements by 2");
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf("%5d", (a[i][j]));
        }
    }
}
void shift_array(int *arr, int n)
{
    int i;
    for (i = 0; i < (n - 2); i++)
    {
        swap(arr + i, arr + (i + 2));
    }
    if (n % 2 != 0)
        swap(arr + i, arr + i + 1);
}
