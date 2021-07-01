#include <stdio.h>
#include <math.h>
void showbits(int, int);
void substring(void);
void main()
{

    printf("\nProgram to show set of all possible finite length strings , defined over an alphabet is infinite\n");
    printf("alphabet contains two strings = '0' & '1' \n");
    printf("\nAll possible combinations of 0 and 1 are\n");
    substring();
}
void showbits(int n, int length)
{
    int bits;
    int k, andmask;

    for (int i = length; i >= 0; i--)
    {
        andmask = 1 << i;
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}
void substring()
{
    int i, j, end;
    for (i = 0; i <= 5; i++)
    {
        printf("\nPossible combinations of length %d is", i);
        if (i == 0)
            printf("\nE");
        else
        {
            end = pow(2, i) - 1;
            for (j = 0; j <= end; j++)
            {
                printf("\n");
                showbits(j, i - 1);
            }
        }
    }
}