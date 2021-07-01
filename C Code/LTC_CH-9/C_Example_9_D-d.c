//Write a program that extracts part of the given string from the;
// specified position. For example, if the sting is "Working with
// strings is fun", then if from position 4, 4 characters are to be
// extracted then the program should return string as "king".
// Moreover, if the position from where the string is to be
// extracted is given and the number of characters to be
// extracted is 0 then the program should extract entire string
// from the specified position.
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    int pos, ch, i = 0;
    char *str;
    printf("\nEnter the string\n");
    gets(str);
    printf("\nThis is the string\" %s\" ", str);
    printf("\nEnter the position from which you want to extract string\n");
    scanf("%d", &pos);
    printf("\nNow enter how many character you want to extract\n");
    scanf("\n%d", &ch);
    str = str + pos - 1;

    if (ch == 0)
    {

        puts(str);
    }
    else
    {
        while (i < ch )
        {
            printf("%c", *str++);
            i++;
        }
    }
}