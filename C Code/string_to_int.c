#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    char str[10];
    int i=0, num = 0;
    printf("\nProgram to convert the string into integer\n");
    printf("Enter the string\n");
    gets(str);

    while (str[i] != '\0')
    {
        num = (10 * num) + str[i]-48;
        i++;
    }
    printf("\n  string '%s' is converted to %d", str, num);
}