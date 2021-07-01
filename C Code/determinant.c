#include <stdio.h>
#include <conio.h>
int determinant(int[][3], int );

void main()
{
    int a[3][3] = {
        {1, 2, 3},
        {2, 4, 2},
        {2, 0, 4}

    };
    printf("\nProgram to find the value of 3x3 determinant matrix");
    printf("\nMatrix \n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%5d", a[i][j]);
        }
    }

    printf("\nThe value of the determinant is %d", determinant(a, 3));
}

int determinant(int a[][3], int r)
{
    int sum = 0;

    for (int i = 0; i < r; i++)
    {
        sum += a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]);
    }
    return sum;
}