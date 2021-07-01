#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int X1 = 0, Y1 = 5, X2 = 8, Y2 = 24, cur_pos = 15;
int arr[15] = {1, 4, 15, 7, 8, 10, 2, 11, 14, 3, 6, 13, 12, 9, 5};
void swap(int *a, int *b)
{
    *b = *a + *b - (*a = *b);
}
void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(h, position);
}
int getkey()
{
    int ch;
    ch = getch();
    if (ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}

void box_value(void)
{

    int i, j, found = 0, count = 0;
    int t;

    // srand(time(0)); //generating random numbers in the matrix
    // while (count < 15)
    // {
    //     found = 0;
    //     t = rand() % 15;
    //     t++;

    //     for (i = 0; i < 15; i++)
    //     {
    //         if (arr[i] == t)
    //         {
    //             found = 1;
    //             break;
    //         }
    //     }
    //     if (found == 0)
    //     {
    //         arr[count] = t;
    //         count++;
    //     }
    // }
    //
    for (int t = 0, i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, t++)
        {
            if (t != 15)
            {
                gotoxy(Y1 + 4 * j + j + 2, X1 + 2 * i + 1);
                printf("%d", arr[t]);
            }
        }
    }
    arr[15] = 0;
}

void update_box_value(void)
{

    int i, j, found = 0, count = 0;
    int t;
    int win = 1;

    for (t = 0, i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, t++)
        {
            gotoxy(Y1 + 4 * j + j + 2, X1 + 2 * i + 1);
            if (arr[t] != 0)
                printf("%d", arr[t]);
            else
                printf("  ");
        }
    }
    for (i = 1; i <= 15; i++)
    {
        if (arr[i - 1] != i)
            win = 0;
    }

    if (win == 1)
    {
        gotoxy(Y1, X2 + 1);
        printf("\n\n!!Great you have Won!!\n\n");
        printf("\nPress any key to exit...");
        getch();
        
        exit(1);
    }
}

void draw_box(void)
{
    system("cls");

    int i, j;

    gotoxy(Y1, X1);
    printf("%c", 218); //corner
    gotoxy(Y2, X1);
    printf("%c", 191);
    gotoxy(Y1, X2);
    printf("%c", 192);
    gotoxy(Y2, X2);
    printf("%c", 217);
    for (i = 0; i < 15; i += 5)
    {
        gotoxy(X2 + i + 1, X1); //upper dividers
        printf("%c", 194);
    }
    for (i = 0; i < 15; i += 5)
    {
        gotoxy(X2 + 1 + i, X1 + 8); //lower dividers
        printf("%c", 193);
    }

    for (i = 0; i < 15; i += 5) //Middle dividers
    {
        for (j = 0; j < 6; j += 2)
        {
            gotoxy(X2 + 1 + i, X1 + 2 + j);
            printf("%c", 197);
        }
    }

    for (i = 0; i < 6; i += 2)
    {
        gotoxy(Y1, X1 + 2 + i); //left side divider
        printf("%c", 195);
    }
    for (i = 0; i < 6; i += 2)
    {
        gotoxy(Y2, X1 + 2 + i); //right side divider
        printf("%c", 180);
    }

    for (i = 0; i < 10; i += 2)
    {
        for (j = 0; j < 19; j++)
        {
            if ((Y1 + 1 + j) % 5 == 4) //horizontal lines
                continue;
            gotoxy(Y1 + 1 + j, X1 + i);
            printf("%c", 196);
        }
    }

    for (i = 0; i < 25; i += 5) //vertical lines
    {
        for (j = 0; j < 8; j += 2)
        {
            if (i != 0)
            {
                gotoxy(Y1 + i - 1, X1 + 1 + j);
                printf("%c", 179);
            }
            else
            {
                gotoxy(Y1 + i, X1 + 1 + j);
                printf("%c", 179);
            }
        }
    }
}

void main()
{
    int key;
    draw_box();
    box_value();
    do
    {
        gotoxy(Y1, X2 + 1);
        printf("Enter any key to move pieces...(ESC to exit)\n");
        key = getkey();
        Beep(750,100);

        switch (key)
        {
        case 72: //upp arrow key
            if (!(cur_pos >= 12 && cur_pos <= 15))
            {
                swap(&arr[cur_pos + 4], &arr[cur_pos]);
                cur_pos += 4;
                update_box_value();
                break;
            }
        case 80: //down arrow key
            if (!(cur_pos >= 0 && cur_pos <= 3))
            {
                swap(&arr[cur_pos - 4], &arr[cur_pos]);
                cur_pos -= 4;
                update_box_value();
                break;
            }
        case 75: //left arrow key
            if (!(cur_pos == 3 || cur_pos == 7 || cur_pos == 11 || cur_pos == 15))
            {
                swap(&arr[cur_pos + 1], &arr[cur_pos]);
                cur_pos += 1;
                update_box_value();
                break;
            }
        case 77: //right arrow key
            if (!(cur_pos == 0 || cur_pos == 4 || cur_pos == 8 || cur_pos == 12))
            {
                swap(&arr[cur_pos - 1], &arr[cur_pos]);
                cur_pos--;
                update_box_value();
                break;
            }
        case 27:
            break;

            // default:
            //     break;
        }
    } while (key != 27);

    //getch();
}
