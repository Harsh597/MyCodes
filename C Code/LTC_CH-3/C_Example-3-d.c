#include <stdio.h>
#include <conio.h>
void main()
{
    printf("\nProgram to find the every possible conbinations of 1,2 and3");
    for (int i = 1; i <= 3; i++)
    {
        printf("\n");

        for (int j = 1; j <= 3; j++)
        {
            printf("\n");
            for (int k = 1; k <= 3; k++)
            {
                printf("\t%d%d%d", i, j, k);
            }
        }
    }
}