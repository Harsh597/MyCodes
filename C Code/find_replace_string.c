#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void main()
{
    char source[30];
    char target[30];
    char *temp;
    char *temp1;
    char *space;
    char *temp2;
    char *newstring[6];
    char words[30];
    char newstr[10][100];
    char last_word[30];
    int i, j, length_0f_string, length_0f_word = 0, t, pos = 0, p, lastword, k, found, m, h;
    char *str[] = {
        "We will tell you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"};
    printf("\n***********Program to find and replace a string from another string*******\n");
    printf("\nThis is the string from which you have to choose which word has to be changed with which word\n");

    for (i = 0; i < 6; i++) //displaying string
    {
        puts(str[i]);
    }
    printf("Enter the string which you want to replace\n");
    gets(source);
    printf("Enter the target string with which you want to replace\n");
    gets(target);

    for (int l = 0; l < 6; l++) //looping line by line
    {
        temp2 = space = (char *)malloc(strlen(str[l]) + strlen(target) - strlen(source) + 1);
        // printf("\n%d is the length of the old string\n", strlen(str[l]));
        // printf("%d is the length of the modified string\n", strlen(space));

        p = 0;
        found = 0;
        temp1 = temp = str[l];
        lastword = 0;

        length_0f_string = strlen(temp); //calculating length of the whole string of line
        temp1 = (str[l] + length_0f_string);

        j = 0;
        while (*temp1 != ' ') //extracting the last word from the whole line
        {
            last_word[j++] = *(--temp1);
        }
        j--;
        last_word[j] = '\0';
        strcpy(last_word, strrev(last_word));

        while ((length_0f_string) >= 0) //looping through each character in the line
        {
            i = 0;

            while (*temp != ' ') //extracting words from the line
            {
                if (!strcmp(source, last_word) && !strcmp(temp, last_word)) //
                {
                    lastword = 1;
                    break;
                }
                words[i] = *temp;
                temp++;

                length_0f_string--;

                i++;
            }

            words[i] = '\0';
            temp++;

            k = 0;
            if (lastword) //copying last word into words
            {
                while (last_word[k] != '\0')
                {
                    words[k] = last_word[k];

                    k++;
                    temp++;
                    length_0f_string--;
                }

                words[k] = '\0';
            }

            if (strcmp(source, words) == 0) //if word found
            {
                found = 1;
                length_0f_word = strlen(words);

                for (int i = length_0f_word; i >= 0; i--) //setting temp to the starting position of the word to be replaced
                {
                    temp--;
                }
                pos = strlen(str[l]) - strlen(temp); //finding the position of the word in the string

                p = 0;
                for (i = 0; i < pos; i++) // assigning the content to new string before the word
                {

                    // strncpy(space,str[l][p],sizeof(str[l][p]));
                    *space = newstr[l][p] = str[l][p];
                    p++;

                    space++;
                }
                puts(temp2);
                m = 0;
                while (target[m] != '\0') // assigning the word to be replaced to the new string
                {
                    // strncpy(space,target[m],sizeof(target[m]));
                    *space = newstr[l][p] = target[m];
                    m++;
                    p++;
                    space++;
                }
                puts(temp2);

                temp1 = temp + strlen(words);
                pos += strlen(words);
                while (p <= strlen(str[l])) //  assigning all the content after the word to the new string
                {

                    *space = newstr[l][p] = *(temp1);
                    //strncpy(space,*temp1,sizeof(newstr[l][p]));
                    p++;
                    space++;
                    temp1++;
                }
                *space = '\0';
                puts(space);
                strcpy(newstring[l], temp2);
                puts(newstring[l]);

                break;
            }
        }

        if (found == 0)
        {

            for (t = 0; t < strlen(str[l]); t++)
            {
                // strncpy(space,str[l][t],sizeof(str[l][t]));
                *space = newstr[l][t] = str[l][t];
                space++;
            }

            //strncpy(space,'\0',sizeof('\0'));
            newstr[l][t] = '\0';
            *space = '\0';

            // strcpy(newstring,str);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(str[i], newstr[i]) != 0) //newstr
        {
            found = 1;

            break;
        }
    }
    // for (int j = h; j < 6; j++)
    // {
    //     strcpy(newstring[j],str[j]);

    // }

    if (found == 1)
    {

        printf("\nModified string is\n");
        for (i = 0; i < 6; i++)
        {
            puts(newstr[i]);
        }
    }
    else
        printf("\nError!! Word not found try again");
}