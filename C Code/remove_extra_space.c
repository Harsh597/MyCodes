#include <stdio.h>
#include <conio.h>

void main()
{
    char source[500], target[500];
    int i = 0, j = 0;
    printf("\nProgram to remove the extra spaces from the string\n");
    gets(source);
    while (source[i] != '\0')
    {

        if ((source[i] == ' '))//first space comes
        {
            target[j] = ' ';
            while (source[i + 1] == ' ')//skipping all the consecutive spaces
                i++;
        }
        else
            target[j] = source[i];

        i++;
        j++;
    }
    target[j] = '\0';
    printf("\nAfter removing extra space string is \n%s ", target);
}