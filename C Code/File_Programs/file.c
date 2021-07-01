#include <stdio.h>
#include <stdlib.h>
void main()
{
    int bytes = 0;
    FILE *fp;
    char ch;

    fp = fopen("C:\\Users\\harsh\\Test.exe", "rb");
    if (fp == NULL)
    {
        printf("\nUnable to open the file\n");
        exit(1);
    }

    while (ch = fgetc(fp) != EOF)
    {
        //printf("%c",ch);
        bytes++;
    }

    printf("\nTotal bytes = %d", bytes);
}