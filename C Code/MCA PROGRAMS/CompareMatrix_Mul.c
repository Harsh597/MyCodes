#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct matrix //matrix structure contains rows,cols, and matrix viz. pointer to an integer
{
    int row;
    int col;
    int *mat;
};
typedef struct matrix mymatrix;
mymatrix multiply(mymatrix mat1, mymatrix mat2)
{
    mymatrix result;
    if ((mat1.col == mat2.row)) //if column in first matrix is equal to row in the second matrix then multiplication is valid otherwise not
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
void output(mymatrix result)
{
    for (int i = 0; i < result.row; i++)
    {
        for (int j = 0; j < result.col; j++)
        {
            printf("%4d", *(result.mat + i * result.col + j));
        }
        printf("\n");
    }
}
void split(mymatrix matC, mymatrix matP, int r, int c)
{
    // int n = matC.row;
    // matC.mat = (int *)malloc((n * n) * sizeof(int));
    for (int i = 0, i1 = r; i < matC.row; i++, i1++)
    {
        for (int j = 0, j1 = c; j < matC.col; j++, j1++)
        {
            (*(matC.mat + i * matC.col + j)) = (*(matP.mat + i1 * matP.col + j1));
        }
    }
}
void join(mymatrix matC, mymatrix matP, int r, int c)
{

    for (int i = 0, i1 = r; i < matC.row; i++, i1++)
    {
        for (int j = 0, j1 = c; j < matC.col; j++, j1++)
        {
            (*(matP.mat + i1 * matP.col + j1)) = (*(matC.mat + i * matC.col + j));
        }
    }
}
mymatrix add(mymatrix mat1, mymatrix mat2)
{
    mymatrix mat3;
    int n = mat1.row;
    mat3.row = mat3.col = n;
    mat3.mat = (int *)malloc((n * n) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*(mat3.mat + i * mat3.col + j)) = (*(mat1.mat + i * mat1.col + j)) + (*(mat2.mat + i * mat2.col + j));
        }
    }
    return mat3;
}
mymatrix sub(mymatrix mat1, mymatrix mat2)
{
    mymatrix mat3;
    int n = mat1.row;
    mat3.row = mat3.col = n;
    mat3.mat = (int *)malloc((n * n) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (*(mat3.mat + i * mat3.col + j)) = (*(mat1.mat + i * mat1.col + j)) - (*(mat2.mat + i * mat2.col + j));
        }
    }
    return mat3;
}
mymatrix StrassenMultiply(mymatrix mat1, mymatrix mat2)
{
    int n = mat1.row;
    mymatrix mat3;
    mat3.row = mat3.col = n;
    mat3.mat = (int *)malloc((n * n) * sizeof(int));
    if (n == 1)
    {
        fflush(stdin);
        (*(mat3.mat + 0 * mat3.col + 0)) = (*(mat1.mat + 0 * mat1.col + 0)) * (*(mat2.mat + 0 * mat2.col + 0));
    }
    else
    {
        fflush(stdin);
        n = n / 2;
        mymatrix matA11, matA12, matA21, matA22, matB11, matB12, matB21, matB22;
        mymatrix matC11, matC12, matC21, matC22;
        matA11.row = matA11.col = n;
        matA12.row = matA12.col = n;
        matA21.row = matA21.col = n;
        matA22.row = matA22.col = n;
        matB11.row = matB11.col = n;
        matB12.row = matB12.col = n;
        matB21.row = matB21.col = n;
        matB22.row = matB22.col = n;

        matA11.mat = (int *)malloc((n * n) * sizeof(int));
        matA12.mat = (int *)malloc((n * n) * sizeof(int));
        matA21.mat = (int *)malloc((n * n) * sizeof(int));
        matA22.mat = (int *)malloc((n * n) * sizeof(int));
        matB11.mat = (int *)malloc((n * n) * sizeof(int));
        matB12.mat = (int *)malloc((n * n) * sizeof(int));
        matB21.mat = (int *)malloc((n * n) * sizeof(int));
        matB22.mat = (int *)malloc((n * n) * sizeof(int));

        matC11.row = matC11.col = n;
        matC12.row = matC12.col = n;
        matC21.row = matC21.col = n;
        matC22.row = matC22.col = n;

        matC11.mat = (int *)malloc((n * n) * sizeof(int));
        matC12.mat = (int *)malloc((n * n) * sizeof(int));
        matC21.mat = (int *)malloc((n * n) * sizeof(int));
        matC22.mat = (int *)malloc((n * n) * sizeof(int));

        split(matA11, mat1, 0, 0);
        split(matA12, mat1, 0, n);
        split(matA21, mat1, n, 0);
        split(matA22, mat1, n, n);
        // output(matA11);
        // output(matA12);
        // output(matA21);
        // output(matA22);

        split(matB11, mat2, 0, 0);
        split(matB12, mat2, 0, n);
        split(matB21, mat2, n, 0);
        split(matB22, mat2, n, n);
        // output(matB11);
        // output(matB12);
        // output(matB21);
        // output(matB22);
        mymatrix p1, p2, p3, p4, p5, p6, p7;
        p1.row = p1.col = n;
        p2.row = p2.col = n;
        p3.row = p3.col = n;
        p4.row = p4.col = n;
        p5.row = p5.col = n;
        p6.row = p6.col = n;
        p7.row = p7.col = n;

        p1.mat = (int *)malloc((n * n) * sizeof(int));
        p2.mat = (int *)malloc((n * n) * sizeof(int));
        p3.mat = (int *)malloc((n * n) * sizeof(int));
        p4.mat = (int *)malloc((n * n) * sizeof(int));
        p5.mat = (int *)malloc((n * n) * sizeof(int));
        p6.mat = (int *)malloc((n * n) * sizeof(int));
        p7.mat = (int *)malloc((n * n) * sizeof(int));

        p3 = StrassenMultiply(matA11, sub(matB12, matB22));
        p5 = StrassenMultiply(add(matA11, matA12), matB22);
        p2 = StrassenMultiply(add(matA21, matA22), matB11);
        p4 = StrassenMultiply(matA22, sub(matB21, matB11));
        p1 = StrassenMultiply(add(matA11, matA22), add(matB11, matB22));
        p7 = StrassenMultiply(sub(matA12, matA22), add(matB21, matB22));
        p6 = StrassenMultiply(sub(matA21, matA11), add(matB11, matB12));

        matC11 = add(sub(add(p1, p4), p5), p7);
        matC12 = add(p3, p5);
        matC21 = add(p2, p4);
        matC22 = add(sub(add(p1, p3), p2), p6);

        join(matC11, mat3, 0, 0);
        join(matC12, mat3, 0, n);
        join(matC21, mat3, n, 0);
        join(matC22, mat3, n, n);

        // int p1 = (a * f) - (a * h);
        // int p2 = (a * h) + (b * h);
        // int p3 = (c * e) + (d * e);
        // int p4 = (d * g) - (d * e);
        // int p5 = (a + d) * (e + h);
        // int p6 = (b - d) * (g + h);
        // int p7 = (a - c) * (e + f);
        free(p1.mat);
        free(p2.mat);
        free(p3.mat);
        free(p4.mat);
        free(p5.mat);
        free(p6.mat);
        free(p7.mat);
        free(matA11.mat);
        free(matA12.mat);
        free(matA21.mat);
        free(matA22.mat);
        free(matB11.mat);
        free(matB12.mat);
        free(matB21.mat);
        free(matB22.mat);
        free(matC11.mat);
        free(matC12.mat);
        free(matC21.mat);
        free(matC22.mat);
    }
    // free(mat1.mat);
    // free(mat2.mat);
    return mat3;
}
int main()
{
    int n;
    clock_t t;
    printf("\nEnter the order of the matrices\n");
    scanf("%d", &n);
    mymatrix mat1, mat2, mat3, mat4;
    mat1.row = n;
    mat1.col = n;
    mat2.row = n;
    mat2.col = n;

    srand(time(0));
    mat1.mat = (int *)malloc((n * n) * sizeof(int));
    mat2.mat = (int *)malloc((n * n) * sizeof(int));
    for (int i = 0; i < n * n; i++) //taking input in the matrix
    {
        fflush(stdin);
        mat1.mat[i] = rand() % 12;
        mat2.mat[i] = rand() % 13;
    }
    output(mat1);
    printf("\n\n");
    output(mat2);
    t = clock();
    mat3 = multiply(mat1, mat2);
    t = clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("time taken using Naive Approach %lf seconds", time_taken);

    printf("\n\n");
    output(mat3);
    printf("\n\n");
    t = clock();
    mat4 = (StrassenMultiply(mat1, mat2));
    t = clock()-t;
    time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("time taken using Strassen Multiply %lf seconds", time_taken);


    return 0;
}
