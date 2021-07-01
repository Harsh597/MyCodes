#include <stdio.h>
void main()
{
    printf("\nProgram to print some patterns\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%2d", j);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%2d", 1);
        }
        printf("\n");
    }
    printf("\n");

    printf("Reverse of the above patterns :\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3 - i + 1; j++)
        {
            printf("%2d", j);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3 - i + 1; j++)
        {
            printf("%2d", 1);
        }
        printf("\n");
    }
}