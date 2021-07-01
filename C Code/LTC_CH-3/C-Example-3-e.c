#include <stdio.h>
#include <conio.h>
void main()
{
    printf("\nProgam to print the table for the given values of y and x  and i\n");
    printf("X\\Y\t1\t2\t3\t4\t5\t6");
    for (float x = 5.5; x <= 12.5; x+=0.5)
    {
        printf("\n %.1f",x);
        for (int y = 1; y <= 6; y++)
        {
            printf("\t %.1f", 2 + (y + 0.5 * x));
        }
    }
}