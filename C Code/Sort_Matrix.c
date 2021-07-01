#include <stdio.h> //Write a program to sort all the elements of a 4 x 4 matrix.
#include <conio.h> //C-Example-8-L-e;
#include "MyLibrary.c"
void main()
{
    int arr[4][4] = {
        {2, 7, 4, 90},
        {71, 12, 78, 22},
        {10, 29, 46, 91},
        {74, 60, 82, 49}

    };
    printf("\nMatrix before sorting\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%5d", arr[i][j]);
        }
    }

    sort_matrix(arr);
    printf("\nProgram to sort all the elements of the 4x4 matrix\n");
    printf("\nMatrix before sorting\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("%5d", arr[i][j]);
        }
    }
}
void sort_matrix(int *a)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = i + 1; j < 16; j++)
        {
            if (*(a + i) > *(a + j))
                swap(a + i, a + j);
        }
    }
}
