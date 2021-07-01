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

void transposeMatrix(int *arr, int row, int col, int val)
{
    int Transpose_arr[val + 1][3];
    int EfficientMatrix[val + 1][3];
    int i, j;
    Transpose_arr[0][1] = EfficientMatrix[0][0] = row;
    Transpose_arr[0][0] = EfficientMatrix[0][1] = col;
    Transpose_arr[0][2] = EfficientMatrix[0][2] = val;
    val = 1;
    //Converting into Efficient Matrix Form
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            if (*(arr + i * col + j) != 0)
            {
                EfficientMatrix[val][0] = i + 1;
                EfficientMatrix[val][1] = j + 1;
                EfficientMatrix[val][2] = *(arr + i * col + j);
                val++;
            }
        }
    displayEfficientMatrix(&EfficientMatrix[0][0], val);
    //Transposing the Efficient Matrix;
    int totalIndex[col];
    int startIndex[col + 1];
    startIndex[0] = 1;
    for (i = 0; i < col; i++)
    {
        totalIndex[i] = 0;
        startIndex[i + 1] = 0;
    }
    for (i = 1; i < val; i++)
    {
        totalIndex[EfficientMatrix[i][1] - 1]++;
    }
    for ( i = 1; i < col + 1; i++)
    {
        startIndex[i] = startIndex[i - 1] + totalIndex[i - 1];
    }

    for (i = 1; i < val; i++)
    {
       Transpose_arr[startIndex[EfficientMatrix[i][1]-1]][0]=EfficientMatrix[i][1];
       Transpose_arr[startIndex[EfficientMatrix[i][1]-1]][1]=EfficientMatrix[i][0];
       Transpose_arr[startIndex[EfficientMatrix[i][1]-1]][2]=EfficientMatrix[i][2];
       startIndex[EfficientMatrix[i][1]-1]++;
    }
    printf("\nAfter Transpose\n");
    displayEfficientMatrix(&Transpose_arr[0][0], val);
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

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%2d ", sparseMatrix[i][j]);
            if (sparseMatrix[i][j] != 0)
                val++;
        }
        printf("\n");
    }

    transposeMatrix(&sparseMatrix[0][0], row, col, val);
    return 0;
}

// 15 0 0 22 0 -15
// 0 0 0 0 0 0
// 91 0 0 0 0 0
// 0 0 28 0 0 0
