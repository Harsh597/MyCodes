#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main(int argc, char *argv[])
{
    FILE *fp;
    char *file = argv[1];
    if (argc != 2)
    {
        printf("\nInvalid arguements\n");
        exit(0);
    }

    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("\nError in opening file\n");
        exit(0);
    }

    while (!feof(fp))
    {
        fputc(fgetc(fp), stdout);
    }
    printf("\nFile Ended");
    fclose(fp);
    getch();
}