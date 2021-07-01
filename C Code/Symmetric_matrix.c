#include <stdio.h>//C Question chapter 8 -Array L-k (Write a program to find if a square matrix is symmetric. )
#include <conio.h>

void main()
{
    int n;
    int flag = 1;
    printf("\nProgram to check whether the matrix is symmetric or not?");
    printf("\nEnter the value of the order of the determinant\n");
    scanf("%d", &n);
    int a[n][n];
    printf("\nEnter the element of the matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
         
        }
    }
    printf("\nYou have enterd this matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%5d", (a[i][j]));
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < i; j++)
        {
            if (a[i][j] != a[j][i])
                flag = 0; //not symmetric
        }
    }
    if (flag == 0)
        printf("\nNot Symmetric");
    else
        printf("\n Symmetric");
}
