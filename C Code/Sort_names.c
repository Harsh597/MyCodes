#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    int i, j;
    char *temp;
    char *names[] = {
        "Harsh",
        "Harshit",
        "Prakhar",
        "Karan",
        "Yash"};
    printf("\nProgram to sort the names stored in the array alphabetically\n");
    printf("Before sorting names are\n");
    for (i = 0; i < 5; i++)
    {
        puts(names[i]);
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if ((strcmp(names[j], names[j + 1])) > 0)
            {
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    printf("After sorting names are\n");
    for (i = 0; i < 5; i++)
    {
        puts(names[i]);
    }
}