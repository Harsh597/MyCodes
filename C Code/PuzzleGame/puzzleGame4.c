#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define _WIN32_WINNT 0x0500

HANDLE wHnd; // Handle to write to the console.
HANDLE rHnd; // Handle to read from the console.
int X1 = 0, Y1 = 5, X2 = 8, Y2 = 24, cur_pos = 15;
// int X1 = 33, Y1 = 6, X2 = 8 +25 , Y2 = 24, cur_pos = 15;

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
    int cur_pos = 15;
    int arr[15] = {1, 4, 15, 7, 8, 10, 2, 11, 14, 3, 6, 13, 12, 9, 5};
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

void update_box_value(int ismain, int moves)
{

    int i, j, found = 0, count = 0;
    int t, key;
    int win = 1;

    gotoxy(124, 0);
    printf("%d", moves);

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
        printf("\nPress ESC key to exit...");
        printf("\nPress Backspace to go back to homescreen...");

        do
        {
            key = getkey();
            if (key == 8) //backspace
            {
                HomeScreen();
            }
            else if (key == 27)
                exit(1);

            //getch();
        } while (key != 27);
    }
}

void draw_box(int dimension,int X1 ,int Y1)
{

    int  X2 = X1 + 2 * dimension, Y2 = Y1 + (5 * dimension), cur_pos = 15;

    system("cls");

    int i, j;
    gotoxy(60, 0);
    printf("moves : ");
    gotoxy(Y1, X1);
    printf("%c", 218); //corner
    gotoxy(Y2, X1);
    printf("%c", 191);
    gotoxy(Y1, X2);
    printf("%c", 192);
    gotoxy(Y2, X2);
    printf("%c", 217);
    for (i = 5; i < 5 * dimension; i += 5)
    {
        gotoxy(Y1 + i, X1); //upper dividers
        printf("%c", 194);
    }
    for (i = 5; i < 5 * dimension; i += 5)
    {
        gotoxy(Y1 + i, X1 + 2 * dimension); //lower dividers
        printf("%c", 193);
    }

    for (i = 5; i < 5 * dimension; i += 5) //Middle dividers
    {
        for (j = 2; j < 2 * dimension; j += 2)
        {
            gotoxy(Y1 + i, X1 + j);
            printf("%c", 197);
        }
    }

    for (i = 2; i < 2 * dimension; i += 2)
    {
        gotoxy(Y1, X1 + i); //left side divider
        printf("%c", 195);
    }
    for (i = 2; i < 2 * dimension; i += 2)
    {
        gotoxy(Y2, X1 + i); //right side divider
        printf("%c", 180);
    }

    for (i = 0; i < 2 * (dimension + 1); i += 2)
    {
        for (j = 1; j < 5 * dimension; j++)
        {
            if ((Y1 + j) % 5 == 4) //horizontal lines
                continue;
            gotoxy(Y1 + j, X1 + i);
            printf("%c", 196);
        }
    }

    for (i = 0; i <= 5 * dimension; i += 5) //vertical lines
    {
        for (j = 1; j < 2 * dimension; j += 2)
        {
            gotoxy(Y1 + i, X1 + j);
            printf("%c", 179);
        }
    }

    // int X1 = 8, Y1 = 24, X2 = X1 + 10, Y2 = Y1 + 25, cur_pos = 15;

    // system("cls");

    // int i, j;
    // gotoxy(60, 0);
    // printf("moves : ");
    // gotoxy(Y1, X1);
    // printf("%c", 218); //corner
    // gotoxy(Y2, X1);
    // printf("%c", 191);
    // gotoxy(Y1, X2);
    // printf("%c", 192);
    // gotoxy(Y2, X2);
    // printf("%c", 217);
    // for (i = 5; i < 25; i += 5)
    // {
    //     gotoxy(Y1 + i, X1); //upper dividers
    //     printf("%c", 194);
    // }
    // for (i = 5; i < 25; i += 5)
    // {
    //     gotoxy(Y1 + i, X1 + 10); //lower dividers
    //     printf("%c", 193);
    // }

    // for (i = 5; i < 25; i += 5) //Middle dividers
    // {
    //     for (j = 2; j < 10; j += 2)
    //     {
    //         gotoxy(Y1 + i, X1 + j);
    //         printf("%c", 197);
    //     }
    // }

    // for (i = 2; i < 10; i += 2)
    // {
    //     gotoxy(Y1, X1 + i); //left side divider
    //     printf("%c", 195);
    // }
    // for (i = 2; i < 10; i += 2)
    // {
    //     gotoxy(Y2, X1 + i); //right side divider
    //     printf("%c", 180);
    // }

    // for (i = 0; i < 12; i += 2)
    // {
    //     for (j = 1; j < 25; j++)
    //     {
    //         if ((Y1 + j) % 5 == 4) //horizontal lines
    //             continue;
    //         gotoxy(Y1 + j, X1 + i);
    //         printf("%c", 196);
    //     }
    // }

    // for (i = 0; i <= 25; i += 5) //vertical lines
    // {
    //     for (j = 1; j < 10; j += 2)
    //     {
    //         gotoxy(Y1 + i, X1 + j);
    //         printf("%c", 179);
    //     }
    // }

    // int X1 = 8, Y1 = 24, X2 = X1 + 8, Y2 = Y1 + 20, cur_pos = 15;

    // system("cls");

    // int i, j;
    // gotoxy(60, 0);
    // printf("moves : ");
    // gotoxy(Y1, X1);
    // printf("%c", 218); //corner
    // gotoxy(Y2, X1);
    // printf("%c", 191);
    // gotoxy(Y1, X2);
    // printf("%c", 192);
    // gotoxy(Y2, X2);
    // printf("%c", 217);
    // for (i = 5; i < 20; i += 5)
    // {
    //     gotoxy(Y1 + i, X1); //upper dividers
    //     printf("%c", 194);
    // }
    // for (i = 5; i < 20; i += 5)
    // {
    //     gotoxy(Y1 + i, X1 + 8); //lower dividers
    //     printf("%c", 193);
    // }

    // for (i = 5; i < 20; i += 5) //Middle dividers
    // {
    //     for (j = 2; j < 8; j += 2)
    //     {
    //         gotoxy(Y1 + i, X1 + j);
    //         printf("%c", 197);
    //     }
    // }

    // for (i = 2; i < 8; i += 2)
    // {
    //     gotoxy(Y1, X1 + i); //left side divider
    //     printf("%c", 195);
    // }
    // for (i = 2; i < 8; i += 2)
    // {
    //     gotoxy(Y2, X1 + i); //right side divider
    //     printf("%c", 180);
    // }

    // for (i = 0; i < 10; i += 2)
    // {
    //     for (j = 1; j < 20; j++)
    //     {
    //         if ((Y1 + j) % 5 == 4) //horizontal lines
    //             continue;
    //         gotoxy(Y1 + j, X1 + i);
    //         printf("%c", 196);
    //     }
    // }

    // for (i = 0; i <= 20; i += 5) //vertical lines
    // {
    //     for (j = 1; j < 8; j += 2)
    //     {
    //         gotoxy(Y1 + i, X1 + j);
    //         printf("%c", 179);
    //     }
    // }
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void shuffle_box()
{
    srand(time(0));

    int key, j = 0;

    {
        int arrowkey[4] = {72, 80, 75, 77};
        // gotoxy(Y1, X2 + 1);
        //printf("Enter any key to move pieces...(ESC to exit)\n");
        key = arrowkey[rand() % 4];
        switch (key)
        {
        case 72: //upp arrow key
            if (!(cur_pos >= 12 && cur_pos <= 15))
            {
                swap(&arr[cur_pos + 4], &arr[cur_pos]);
                cur_pos += 4;
                update_box_value(0, 0);
                break;
            }
        case 80: //down arrow key
            if (!(cur_pos >= 0 && cur_pos <= 3))
            {
                swap(&arr[cur_pos - 4], &arr[cur_pos]);
                cur_pos -= 4;
                update_box_value(0, 0);
                break;
            }
        case 75: //left arrow key
            if (!(cur_pos == 3 || cur_pos == 7 || cur_pos == 11 || cur_pos == 15))
            {
                swap(&arr[cur_pos + 1], &arr[cur_pos]);
                cur_pos += 1;
                update_box_value(0, 0);
                break;
            }
        case 77: //right arrow key
            if (!(cur_pos == 0 || cur_pos == 4 || cur_pos == 8 || cur_pos == 12))
            {
                swap(&arr[cur_pos - 1], &arr[cur_pos]);
                cur_pos--;
                update_box_value(0, 0);
                break;
            }
        case 27:
            break;

            // default:
            //     break;
        }
        j++;
        delay(0.999);
    }
    while (key != 27 && j < 100)
        ;

    //getch();
}

void mainGame()
{
    int x1=8;
    int y1=24;
    int key;
    int moves = 0;
    int dimension = 4;
    draw_box(dimension,x1,y1);
    box_value();
    shuffle_box();
    int ismain = 1;
    do
    {
        //gotoxy(Y1, X2 + 1);
        //printf("Enter any key to move pieces...(ESC to exit)\n");
        key = getkey();
        Beep(1500, 10);
        //Beep(1300, 50);

        switch (key)
        {
        case 72: //upp arrow key

            if (!(cur_pos >= 12 && cur_pos <= 15))
            {

                swap(&arr[cur_pos + 4], &arr[cur_pos]);
                cur_pos += 4;
                update_box_value(ismain, ++moves);
                break;
            }
        case 80: //down arrow key
            if (!(cur_pos >= 0 && cur_pos <= 3))
            {
                swap(&arr[cur_pos - 4], &arr[cur_pos]);
                cur_pos -= 4;
                update_box_value(ismain, ++moves);
                break;
            }
        case 75: //left arrow key
            if (!(cur_pos == 3 || cur_pos == 7 || cur_pos == 11 || cur_pos == 15))
            {
                swap(&arr[cur_pos + 1], &arr[cur_pos]);
                cur_pos += 1;
                update_box_value(ismain, ++moves);
                break;
            }
        case 77: //right arrow key
            if (!(cur_pos == 0 || cur_pos == 4 || cur_pos == 8 || cur_pos == 12))
            {
                swap(&arr[cur_pos - 1], &arr[cur_pos]);
                cur_pos--;
                update_box_value(ismain, ++moves);
                break;
            }

        case 27:
            exit(1);
            // default:
            //   Beep(1300, 50);
        }
        //  nosound();

    } while (key != 27);
}

void HomeScreen()
{
    int key;
    int c_x = 35 / 2;
    int c_y = 65 / 2;
    c_x -= 2;
    system("cls");
    gotoxy(15, c_x);
    printf("NUMBER PUZZLE GAME\n");
    gotoxy(15, c_x + 1);
    printf("PRESS ENTER TO PLAY GAME\n");
    do
    {
        key = getkey();
        if (key == 13)
        {
            // shuffle_box();
            mainGame();
        }

    } while (key != 13 || key != 8);
}
int main()
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Advanced C tutorial - programming-technique.blogspot.com");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 65, 35};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(wHnd, &info);
    COORD new_size =
        {
            info.srWindow.Right - info.srWindow.Left + 1,
            info.srWindow.Bottom - info.srWindow.Top + 1};
    SetConsoleScreenBufferSize(wHnd, new_size);

    HomeScreen();

    getch();
    return 0;
}
