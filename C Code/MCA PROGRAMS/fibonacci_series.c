#include <stdio.h>
void main()
{
    int n, i;
    int a = 0, b = 1, c;

    printf("\nProgram to print the fibonacci series\n");
    printf("Enter the number of terms you want in the series\n");
    scanf("%d", &n);
    if (n == 1)
        printf("%d", a);
    else if (n == 2)
        printf("%d %d", a, b);
    else
    {
        printf("%d %d ", a, b);

        for (i = 3; i <= n; i++)
        {

            c = a + b;
            a = b;
            b = c;
            printf(" %d ", c);
        }
    }
}