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
    char *newstring[6];
    char words[30];
    char newstr[10][100];
    char last_word[30];
    int i, j, length_0f_string, length_0f_word = 0, t, pos = 0, p, lastword, k, found, m;
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
            fflush(stdin);

    gets(source);
    printf("Enter the target string with which you want to replace\n");
            fflush(stdin);

    gets(target);

    for (int l = 0; l < 6; l++) //looping line by line
    {
      //  space=(char *)malloc(strlen(str[l])+strlen(target)-strlen(source)+1);
        p = 0;
        found = 0;
        temp1 = temp = str[l];
        lastword = 0;
            fflush(stdin);

        length_0f_string = strlen(temp); //calculating length of the whole string of line
            fflush(stdin);

        temp1 = (str[l] + length_0f_string);

        j = 0;
        while (*temp1 != ' ') //extracting the last word from the whole line
        {
            fflush(stdin);

            last_word[j++] = *(--temp1);
        }
        j--;
            fflush(stdin);

        last_word[j] = '\0';
            fflush(stdin);

        strcpy(last_word, strrev(last_word));

        while ((length_0f_string) >= 0) //looping through each character in the line
        {
            fflush(stdin);

            i = 0;

            while (*temp != ' ') //extracting words from the line
            {
            fflush(stdin);

                if (!strcmp(source, last_word) && !strcmp(temp, last_word)) //
                {
                    lastword = 1;
                    break;
                }
            fflush(stdin);

                words[i] = *temp;
                temp++;

                length_0f_string--;

                i++;
            }
            fflush(stdin);

            words[i] = '\0';
            temp++;

            k = 0;
            if (lastword) //copying last word into words
            {
                while (last_word[k] != '\0')
                {
            fflush(stdin);
                    
                    words[k] = last_word[k];

                    k++;
                    temp++;
                    length_0f_string--;
                }
            fflush(stdin);

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
            fflush(stdin);

                  //  strncpy(space,str[l][p],1);
                    newstr[l][p] = str[l][p];
                    p++;
                   
              //      space++;
                }
                m = 0;
                while (target[m] != '\0') // assigning the word to be replaced to the new string
                {
            fflush(stdin);

                    // strncpy(space,target[m],1);
                    newstr[l][p] = target[m];
                    m++;
                    p++;
            //        space++;
                }

                temp1 = temp + strlen(words);
                pos += strlen(words);
                while (p <= strlen(str[l])) //  assigning all the content after the word to the new string
                {
            fflush(stdin);
                     
                    newstr[l][p] = *(temp1++);
                //    strncpy(space,newstr[l][p],1);
                    p++;
        //            space++;
                }
                break;
            }
        }

        if (found == 0)
        {

            for (t = 0; t < strlen(str[l]); t++,space++)
            {
            fflush(stdin);

          //      strncpy(space,str[l][t],1);
                newstr[l][t] = str[l][t];

            }
            //*space='\0';
            fflush(stdin);
            newstr[l][t] = '\0';
           // space-=strlen(space);
            //newstring[l]=space;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(str[i], newstr[i]) != 0)
        {
            found = 1;
            break;
        }
    }

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