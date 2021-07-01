#include <string.h>
#include <stdio.h>
#include <conio.h>
void xstrrev(char *);
void main()
{
    char *s[] = {
        "To err is human...",
        "But to really mess things up...",
        "One needs to know C!!"};
    printf("\nProgram to reverse the string\n");
    for (int i = 0; i < 3; i++)
    {
        xstrrev(s[i]);
        printf("\n");
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     puts(s[i]);
    // }
}
void xstrrev(char *str)
{
    int len = strlen(str);
    str += len;
    //char *rev;
    while (len-- >= 0)
    {
        
        printf("%c", *(str));
        str--;
        //rev++;
    }
}