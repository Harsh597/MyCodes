#include <stdio.h>
#include <stdlib.h>
struct matrix //matrix structure contains rows,cols, and matrix viz. pointer to an integer
{
    int row;
    int col;
    int *mat;
};
typedef struct matrix mymatrix;
// (*(mat1.mat + i * mat1.col + k)) represents=mat1[i][j].
// Similarily (*(mat2.mat + i * mat2.col + k)) represents =mat2[i][j];
mymatrix input()
{
    mymatrix mat1;

    fflush(stdin);
    printf("\nEnter the number of rows\n");
    scanf("%d", &mat1.row);
    printf("\nEnter the number of columns\n");
    scanf("%d", &mat1.col);
    mat1.mat = (int *)malloc((mat1.row * mat1.col) * sizeof(int));
    printf("\nNow enter the elements of the matrix\n");
    for (int i = 0; i < mat1.row * mat1.col; i++)//taking input in the matrix
    {
        scanf("%d", &mat1.mat[i]);
    }
    return mat1;
}
mymatrix diff(mymatrix mat1, mymatrix mat2)
{
    mymatrix result;
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))//if dimensions are same then do difference
    {
        result.row = mat1.row;
        result.col = mat1.col;
        result.mat = (int *)malloc((mat1.row * mat1.col) * sizeof(int));
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
                (*(result.mat + i * result.col + j)) = (*(mat1.mat + i * mat1.col + j)) - (*(mat2.mat + i * mat2.col + j));
        }
    }
    else//otherwise not possible
    {
        printf("\nDiff is not possible\n");
        result.row = -1;
        result.col = -1;
    }
    return result;
}
mymatrix multiply(mymatrix mat1, mymatrix mat2)
{
    mymatrix result;
    if ((mat1.col == mat2.row))//if column in first matrix is equal to row in the second matrix then multiplication is valid otherwise not
    {
        result.row = mat1.row;
        result.col = mat2.col;
        result.mat = (int *)malloc((mat1.row * mat2.col) * sizeof(int));
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat2.col; j++)
            {
                (*(result.mat + i * result.col + j)) = 0;
                for (int k = 0; k < mat2.row; k++)
                {
                    (*(result.mat + i * result.col + j)) += (*(mat1.mat + i * mat1.col + k)) * (*(mat2.mat + k * mat2.col + j));
                }
            }
        }
    }
    else
    {
        printf("\nMultiplication  is not possible\n");
        result.row = -1;
        result.col = -1;
    }
    return result;
}
mymatrix sum(mymatrix mat1, mymatrix mat2)
{
    mymatrix result;
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        result.row = mat1.row;
        result.col = mat1.col;
        result.mat = (int *)malloc((mat1.row * mat1.col) * sizeof(int));
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
                (*(result.mat + i * result.col + j)) = (*(mat1.mat + i * mat1.col + j)) + (*(mat2.mat + i * mat2.col + j));
        }
    }
    else
    {
        printf("\nSum is not possible\n");
        result.row = -1;
        result.col = -1;
    }
    return result;
}
void output(mymatrix result)
{
    if (!(result.col == -1 && result.row == -1))
    {
        for (int i = 0; i < result.row; i++)
        {
            for (int j = 0; j < result.col; j++)
            {
                printf("%3d", *(result.mat + i * result.col + j));
            }
            printf("\n");
        }
    }
}
int main()
{
    mymatrix mat1, mat2;
    mymatrix result;
    printf("\n Program for Matrix Operations (Sum , Difference & Multiplication\n");
    printf("\nEnter the dimension for the first matrix\n");
    mat1 = input();
    printf("\nEnter the dimension for the second matrix\n");
    mat2 = input();
    // result = sum(mat1, mat2);
    // output(result);
    // printf("\n\n");

    // result = diff(mat1, mat2);
    // output(result);
    // printf("\n\n");

    result = multiply(mat1, mat2);
    output(result);

    return 0;
}