#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void main(int argc, char *argv[])
{
    FILE *fp;
    char *file = argv[1];
    char word[11];
    char ch;
    int i;

    if (argc != 2)
    {
        printf("\nInvalid arguements\n");
        exit(0);
    }

    fp = fopen(file, "rb");
    if (fp == NULL)
    {
        printf("\nError in opening file\n");
        exit(0);
    }
    i = 0;
    while (!feof(fp))
    {
        ch = fgetc(fp);

        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF) ||ch =='.'
        {
            fseek(fp, -i - 1, SEEK_CUR);
            if (ch != EOF)
            {
                fgets(word, i + 1, fp);
                fseek(fp, 1+1, SEEK_CUR);
                printf("%s", strrev(word));
                printf("%c", ch);

                i = 0;
            }
            else
            {
                fgets(word, i + 2, fp);
                printf("%s", strrev(word));
                break;
            }
        }
        i += 1;
    }
    fclose(fp);
}