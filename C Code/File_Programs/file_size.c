#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void main()
{
    FILE *fp;
    int size = 0,len;
    char file[100];

    printf("Enter the file name\n");
    gets(file);

    fp = fopen( file, "rb");
    if (fp == NULL)
    {
        printf("Error in opening file");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    printf("\nThe size of the given file is %f", (float)size / 1024);
    fclose(fp);
}