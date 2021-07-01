#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int r, c;
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
    norm_matrix(a, r, c);
}
void norm_matrix(int *a, int r, int c)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            sum += pow(*(a + i * c + j), 2);
        }
    }
    printf("\nNorm of the matrix is=%f", sqrt(sum));
}
