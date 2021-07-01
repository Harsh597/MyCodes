#include <stdio.h>
#include <conio.h>

void main()
{
    int n;
    printf("\nProgram to find the value of the determinant of any order");
    printf("\nEnter the value of the order of the determinant\n");
    scanf("%d", &n);
    int a[n][n];

    printf("\nThis is the random determinant for the value is to be calculated");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {

            printf("%5d", (a[i][j] = (a[i][j]) % 9));
            //  a[i][j]=(a[i][j]) % 9;
        }
    }
    printf("\n");
    printf("\n");

    int t = determinant(a, n);
    printf("\nvalue of determinant is  %d", t);
}
int determinant(int *a, int n) //a[i][j]=*(a + i * n + j)
{
    int p, t, det;
    if (n == 2)
    {

        p =  (*(a + 0 * (n + 1) + 0) *  *(a + 1 * (n + 1) + 1) -  *(a + 1 * (n + 1) + 0) *  *(a + 0 * (n + 1) + 1));
        printf("\np= %d", p);

        return p;
    }
    else
    {
        det = 0;
        t = *(a + 0 * n + 0) = -1 * *(a + 0 * n + 0);
        printf("\nt= %d", t);

        for (int i = 0; i < n; i++)
        {
            det += -1 * *(a + 0 * n + i) * determinant((a + (i + 1) * n + (i + 1)), n - 1);
        }
    }
}