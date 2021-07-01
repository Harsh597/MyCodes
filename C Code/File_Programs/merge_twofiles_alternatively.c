#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1, *fp2, *fp3;
    char file1[100], file2[100], ch;
    int active_file = 1;
    printf("Enter the file1\n");
    gets(file1);
    printf("Enter the file2\n");
    gets(file2);
    fp1 = fopen(file1, "rb");
    fp2 = fopen(file2, "rb");
    fp3 = fopen("merge.txt", "wb");
    if (fp1 == NULL)
    {
        printf("\nError in opening file1\n");
        exit(1);
    }
    if (fp2 == NULL)
    {
        printf("\nError in opening file2\n");
        exit(1);
    }
    if (fp3 == NULL)
    {
        printf("\nError in opening file3\n");
        exit(1);
    }
    while (1)
    {
        if (active_file == 1)
        {
            ch = fgetc(fp1);
            if (ch == EOF)
                break;
            else if (ch == '\n')
            {
                //fputc(ch, fp3);

                active_file = 2;
            }
            fputc(ch, fp3);
        }
        else if (active_file == 2)
        {
            ch = fgetc(fp2);
            if (ch == EOF)
                break;
            else if (ch == '\n')
            {
                //fputc(ch, fp3);

                active_file = 1;
            }
            fputc(ch, fp3);
        }
    }
    if ((ch = fgetc(fp1)) == EOF)
    {
            fputc('\n', fp3);

        while ((ch = fgetc(fp2)) != EOF)
        {
            fputc(ch, fp3);
        }
    }
    else if ((ch = fgetc(fp2)) == EOF)
    {
            fputc('\n', fp3);

        while ((ch = fgetc(fp1)) != EOF)
        {
            fputc(ch, fp3);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}