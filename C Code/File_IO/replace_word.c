#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define EndOfWord word[i] == ' ' || word[i] == ',' || word[i] == '\n' || word[i] == '.'

int main(int ac, char *av[])
{
    FILE *fp, *temp;
    int i, j;
    char word[10], ch;
    if (ac != 4)
    {
        puts("Wrong number of arguements\n.");
        printf("Write like this : ");
        printf("\"change\" \"old_word\"");
        printf("\"new_word\" \"file_name\"\n");
        exit(1);
    }
    fp = fopen(av[3], "r");
    temp = fopen("temp.txt", "w");
    if (fp == NULL)
    {
        perror("Error : ");
        exit(1);
    }
    for (i = 0; (word[i] = fgetc(fp)) != EOF; i++)
    {
        if (EndOfWord)
        {
            ch = word[i];
            word[i] = '\0';
            if (!strcmp(av[1], word))
                fputs(av[2], temp);
            else
                fputs(word, temp);
            fputc(ch, temp);
            i = -1;
        }
    }
    word[i] = '\0';
    fputs(word, temp);

    fclose(fp);
    fclose(temp);
    remove(av[3]);
    rename("temp.txt", av[3]);
    return 0;
}