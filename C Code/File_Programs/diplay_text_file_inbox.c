#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
int x1 = 1, y1 = 0, x2 = 23, y2 = 79;
void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(h, position);
}
void draw_box()
{
    int i, j;
    system("cls");
    // corners
    gotoxy(y1, x1);
    //printf("%c", 218);
    printf("%c", 201);

    gotoxy(y2, x1);
    // printf("%c", 191);
    printf("%c", 187);

    gotoxy(y1, x2);
    // printf("%c", 192);
    printf("%c", 200);

    gotoxy(y2, x2);
    //printf("%c", 217);
    printf("%c", 188);

    //upper lines
    for (i = 1; i < y2; i++)
    {
        gotoxy(y1 + i, x1);

        printf("%c", 205);
    }
    //lower lines
    for (i = 1; i < y2; i++)
    {
        gotoxy(y1 + i, x2);

        printf("%c", 205);
    }
    //left lines
    for (i = 1; i < x2 - 1; i++)
    {
        gotoxy(y1, x1 + i);

        printf("%c", 186);
    }

    //right lines
    for (i = 1; i < x2 - 1; i++)
    {
        gotoxy(y2, x1 + i);

        printf("%c", 186);
    }
}
void main()
{
    FILE *fp;
    char ch, file_name[30], file_loc[80];
    int page = 1, i, j;
    int x = 0, y = 0;
    printf("\nEnter file name\n");
    gets(file_name);
    printf("\nEnter file location\n");
    gets(file_loc);
    fp = fopen(file_loc, "rb");
    if (fp == NULL)
    {
        gotoxy(y1 + 1, x1 + 1);
        printf("\nError in opening file\n");
        exit(1);
    }
    //drawing box
    draw_box();
    //displaying file name
    gotoxy(y1 + 1, x1 + 1);
    printf("%s", file_name);
    //displaying page no.
    gotoxy(y2 - 5, x1 + 1);
    printf("%d", page);
    //line after file name and page no.
    for (i = 1; i < y2; i++)
    {
        gotoxy(y1 + i, x1 + 2);

        printf("%c", 196);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        //next line
        if ((y1 + y + 1) >= 78 || ch == '\n')
        {
            x++;
            y = 0;
        }
        //if box content is full
        if ((x1 + 3 + x) >= 22)
        {
            gotoxy(y1 + y + 1, x1 + 3 + x);
            printf(" \t\t\t\tpress any key ...");
            fflush(stdin);
            getch();
            //clear the box content
            for (i = y1 + 4; i < x2; i++)
            {
                for (j = x1; j < y2; j++)
                {
                    gotoxy(j, i);
                    printf(" ");
                }
            }

            x = 0;
            y = 0;
            page++;
            gotoxy(y2 - 5, x1 + 1);
            printf("%d", page);
        }
        gotoxy(y1 + 1 + y, x1 + 3 + x);
        y++;
        printf("%c", ch);
    }
    gotoxy(y1 + y + 1, x1 + 15 + x);
    printf(" File Ended\t\t\t Press any key to exit....");
    getch();
    fclose(fp);
}