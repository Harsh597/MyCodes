#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    char file[500], ch;
    int line_no = 1;

    printf("Enter the file name you want to open\n");
    //fgets(file, 50, stdin);

    gets(file);
    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Error in opening the file");
        exit(1);
    }

   while ((ch = fgetc(fp)) != EOF)
    {
         if (line_no == 1)
        {
            printf("\r%d ", line_no++);
        }
        printf("%c", ch);

       
         if (ch == '\n')
          printf("\r%d ", line_no++);

    }
    fclose(fp);
}