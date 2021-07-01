#include <stdio.h>
#include <conio.h>
void main()
{

    char color;
    int num;

    //clrscr();

    printf("Please enter the number(0-6): ");
    scanf("%d", &num);

    color = 1 << num;

    printf("\n\n");

    if (num == 0 && color == 1)
        printf("Violet");

    else if (num == 1 && color == 2)
        printf("Indigo");

    else if (num == 2 && color == 4)
        printf("Blue");

    else if (num == 3 && color == 8)
        printf("Green");

    else if (num == 4 && color == 16)
        printf("Yellow");

    else if (num == 5 && color == 32)
        printf("Orange");

    else if (num == 6 && color == 64)
        printf("Red");

    else
        printf("Wrong color number!");

    getch();
}
