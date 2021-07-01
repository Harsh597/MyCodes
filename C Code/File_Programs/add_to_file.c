#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1, *fp2;
    char file1[500], file2[500], ch;

    printf("Enter the file in which you want to add more content at the end\n");
    gets(file1);
    printf("Enter the file whose content want to add\n");
    gets(file2);
    fp2 = fopen(file2, "r");
    fp1 = fopen(file1, "a");
    if (fp2 == NULL || fp1 == NULL)
    {
        printf("\nError in opening file");
        exit(1);
    }
    while ((ch = fgetc(fp2)) != EOF)
    {
        fputc(ch, fp1);
        printf("%c", ch);
    }
    fclose(fp1);
    fclose(fp2);
}