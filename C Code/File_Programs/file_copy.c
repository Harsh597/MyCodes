#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *fp1, *fp2;
    char file1[100], ch;
    printf("Enter the file names whose copy you want to creat\n");
    gets(file1);
    fp1 = fopen(file1, "rb");
    fp2 = fopen("\\.\\copy", "wb");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("\nError in opening the file\n");
        exit(1);
    }
    while ((ch = fgetc(fp1)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;
        }
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}
