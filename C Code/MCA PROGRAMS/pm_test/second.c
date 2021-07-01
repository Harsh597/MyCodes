#include <stdio.h>
#include <string.h>

void main()
{
    char str[20];
    printf("Enter any string\n");
    fgets(str, 20, stdin);

    change_case(str);
}
void change_case(char str[])
{
    char ch;
    for (int i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        if (ch >= 65 && ch <= 90)
        {
            ch += 32;
            puts(ch);
        }
        else
        {
            ch -= 32;
            puts(ch);
        }
    }
}