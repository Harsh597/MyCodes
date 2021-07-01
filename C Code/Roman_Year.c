#include <stdio.h>
#include <conio.h>

char *year_to_roman(int);
void main()
{
    int year;
    char ch;
    printf("Program to convert any year into roman equivalent\n");
    printf("\nEnter any year\n");
    scanf("%d", &year);
    printf("\nRoman equivalent of the %d is ", year);
    ch = *year_to_roman(year);
    while (ch != '\0')
    {
        printf("%c", ch);
    }
}
char *year_to_roman(int year)
{
    char ch[20];
    int j = 0;
    switch (1)
    {
    case 1:
        if (year == 9)
        {
            printf("ix");
            ch[j] = 'ix';
            j++;
            break;
        }
        else if (year == 4)
        {
            printf("iv");
            ch[j] = 'iv';
            j++;
            break;
        }
        else
        {
            for (int i = 1; i <= (year / 1000); i++, j++)
            {
                printf("m");
                ch[j] = 'm';
            }
            year = year % 1000;
        }
    case 2:
        for (int i = 1; i <= (year / 500); i++, j++)
        {
            printf("d");
            ch[j] = 'd';
        }
        year = year % 500;

    case 3:
        for (int i = 1; i <= (year / 100); i++, j++)
        {
            printf("c");
            ch[j] = 'c';
        }
        year = year % 100;

    case 4:
        for (int i = 1; i <= (year / 50); i++, j++)
        {
            printf("l");
            ch[j] = 'l';
        }
        year = year % 50;

    case 5:
        for (int i = 1; i <= (year / 10); i++, j++)
        {
            printf("x");
            ch[j] = 'x';
        }
        year = year % 10;

    case 6:
        for (int i = 1; i <= (year / 5); i++, j++)
        {

            printf("v");
            ch[j] = 'v';
        }
        year = year % 5;

    case 7:
        for (int i = 1; i <= (year / 1); i++, j++)
        {
            printf("i");
            ch[j] = 'i';
        }
        year = year % 1;
        ch[j] = '\0';

    default:
        
        break;
    }
    return ch;
}