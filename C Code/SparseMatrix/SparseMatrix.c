#include <stdio.h>
void displayEfficientMatrix(int *arr, int val)
{
    printf("\nSparse Matrix : Efficient Representation\n\n");
    printf("Index \tRow \tCol \tVal\n");
    for (int i = 0; i < val; i++)
    {
        printf("%2d\t", i);
        for (int j = 0; j < 3; j++)
        {
            printf("%2d\t", *(arr + i * 3 + j));
        }
        printf("\n");
    }
}
void toEfficientMatrix(int *arr, int row, int col, int val)
{
    int EfficientMatrix[val + 1][3];
    EfficientMatrix[0][0] = row;
    EfficientMatrix[0][1] = col;
    EfficientMatrix[0][2] = val;
    val = 1;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (*(arr + i * 6 + j) != 0)
            {
                EfficientMatrix[val][0] = i + 1;
                EfficientMatrix[val][1] = j + 1;
                EfficientMatrix[val][2] = *(arr + i * 6 + j);
                val++;
            }
        }
    displayEfficientMatrix(&EfficientMatrix[0][0], val);
}
int main()
{

    int row, col, i, j;
    int val = 0;

    printf("Enter no. of rows in the matrix\n");
    scanf("%d", &row);
    printf("Enter no. of cols in the matrix\n");
    scanf("%d", &col);
    printf("\nNow Enter the elements of the matrix\n");
    int sparseMatrix[row][col];
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &sparseMatrix[i][j]);
    printf("Sparse Matrix : Normal Representation\n\n");

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            printf("%2d ", sparseMatrix[i][j]);
            if (sparseMatrix[i][j] != 0)
                val++;
        }
        printf("\n");
    }

    toEfficientMatrix(&sparseMatrix[0][0], row, col, val);

    return 0;
}


// 15 0 0 22 0 -15
// 91 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 28 0 0 0