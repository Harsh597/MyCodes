#include <stdio.h>
#include <conio.h>
#define isUpper(ch) (ch >= 65 && ch <= 90 ? 1 : 0)
#define isLower(ch) (ch >= 97 && ch <= 122 ? 1 : 0)
#define isAlpha(ch) (isUpper(ch) || isLower(ch) ? 1 : 0)
#define isBig(x, y) (x > y ? x : y)

void main()
{
    char ch;
    int a, b, d;
    printf("\nProgram to find whether the entered char is in lower case ,upper case etc..");
    printf("\nEnter the character\n");
    scanf("%c", &ch);
    if (isUpper(ch))
        printf("\nYou have entered a Upper case letter");
    else if (isLower(ch))
        printf("\nYou have entered a Lower case letter");
    else if (!isAlpha(ch))
        printf("\nYou have entered a character which is not a alphabet");
    printf("\nEnter any two numbers\n");
    scanf("%d %d", &a, &b);
    d = isBig(a, b);
    printf("\n%d is bigger    ", d);
}
