#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
// #define _WIN32_WINNT 0x0500
HANDLE wHnd; // Handle to write to the console.
HANDLE rHnd; // Handle to read from the console.
int sound = 1;
struct score
{
    int dimension;
    int moves;
} typedef Score;
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

void box_value(int arr1[], int dimension, int x1, int y1)
{
    int i, j, t;
    int size = dimension * dimension;
    for (int t = 1, i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++, t++)
        {
            if (t != size)
            {
                gotoxy(y1 + 4 * j + j + 2, x1 + 2 * i + 1);
                printf("%d", (arr1[t]));
            }
        }
    }
}
void wingame(int arr1[], int dimension, int moves, int lastbest)
{
    int k = 0, key;
    int mid_col = (65) / 2 - 15;
    char buttons[][7] = {" HOME ",
                         " NEXT "};
    char *result[] = {"Congrats!!",
                      "  You won the game!! ",
                      "                  ",
                      "    \t Moves :",
                      "                  ",
                      "  Last Best :"};
    int found = 0;
    Score sc;
    FILE *fp;
    fp = fopen("Score.txt", "rb+");
    if (fp == NULL)
    {
        fp = fopen("Score.txt", "wb+");
    }
    fseek(fp, 0, SEEK_END);

    if (ftell(fp) > 0)
    {
        rewind(fp);
        while (fread(&sc, sizeof(sc), 1, fp) == 1)
        {
            if (sc.dimension == dimension)
            {
                found = 1;
                if (moves < lastbest)
                {
                    fseek(fp, -sizeof(sc), SEEK_CUR);
                    sc.moves = moves;
                    fwrite(&sc, sizeof(sc), 1, fp);
                }
                break;
            }
        }
        if (found == 0)
        {
            sc.dimension = dimension;
            sc.moves = moves;
            fwrite(&sc, sizeof(sc), 1, fp);
        }
    }
    else
    {
        sc.dimension = dimension;
        sc.moves = moves;
        fwrite(&sc, sizeof(sc), 1, fp);
    }
    fclose(fp);
    if (moves < lastbest)
    {
        result[0] = "Congrats!! New Record";
    }
    else
        result[0] = "Congrats!!";

    contentbox(mid_col, 10, mid_col + 27, 21, result, 6, 1);
    boldbox(mid_col + 2, 19, buttons[k]);
    smallbox(mid_col + 20, 19, buttons[1]);
    gotoxy(mid_col + 16, 14);
    printf("%-3d", moves);
    if (lastbest != 0)
    {
        gotoxy(mid_col + 16, 16);
        printf("%-3d", lastbest);
    }
    else
    {
        gotoxy(mid_col + 16, 16);
        printf("NILL");
    }

    do
    {
        key = getkey();
        Beep(1500 * sound, 10);
        Beep(1300 * sound, 50);
        if (key == 9) //tabkey
        {
            k++;
        }
        else if (key == 77) //right arrow key
            k++;
        else if (key == 75) //left arrow key
            k--;
        if (k > 1)
            k = 0;
        else if (k < 0)
            k = 1;
        if (key == 13)
        {
            if (k == 0)
            {
                HomeScreen();
            }
            else if (k == 1)
            {
                dimension++;
                if (dimension > 8)
                    dimension = 3;
                mainGame(arr1, dimension);
            }
        }

        if (k == 0)
        {
            boldbox(mid_col + 2, 19, buttons[k]);
            smallbox(mid_col + 20, 19, buttons[1]);
        }
        else if (k == 1)
        {
            smallbox(mid_col + 2, 19, buttons[0]);
            boldbox(mid_col + 20, 19, buttons[k]);
        }
    } while (key != 13);
}
int PrevScore(int moves, int dimension)
{
    Score sc;
    FILE *fp;
    int found = 0;
    int lastbest;
    fp = fopen("Score.txt", "rb+");
    rewind(fp);
    while (fread(&sc, sizeof(sc), 1, fp) == 1)
    {
        if (sc.dimension == dimension)
        {
            lastbest = sc.moves;
            found = 1;
        }
    }
    if (found == 0)
    {
        lastbest = 0;
    }
    fclose(fp);
    return lastbest;
}
void DisplayScore()
{

    char dimension[][16] = {"   3 X 3  :    ", "   4 X 4  :    ", "   5 X 5  :    ", "   6 X 6  :    ", "   7 X 7  :    ", "   8 X 8  :    "};
    char *about[] = {"Different Levels",
                     "3x3 :  Beginners",
                     "4x4 :  Classix",
                     "5x5 :  Smart",
                     "6x6 :  Challenger",
                     "7x7 :  Expert",
                     "8x8 :  Master"};
    int box_x = 7;
    int box_y = 27;
    int key, back, dimen, found = 0;
    Score sc;
    FILE *fp;
    fp = fopen("Score.txt", "rb+");
    if (fp == NULL)
    {
        fp = fopen("Score.txt", "wb+");
    }
    system("cls");
    smallbox(1, 1, " <-- ");
    gotoxy(30, 5);

    printf("SCORES");

    smallbox(box_y, box_x, dimension[0]);
    smallbox(box_y, box_x + 3, dimension[1]);
    smallbox(box_y, box_x + 6, dimension[2]);
    smallbox(box_y, box_x + 9, dimension[3]);
    smallbox(box_y, box_x + 12, dimension[4]);
    smallbox(box_y, box_x + 15, dimension[5]);
    contentbox(6, 25, 62, 35, about, 7, 0);
    dimen = 3;
    while (dimen <= 8)
    {
        rewind(fp);
        found = 0;
        while (fread(&sc, sizeof(sc), 1, fp) == 1)
        {
            if (sc.dimension == dimen)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {
            gotoxy(box_y + 11, box_x + (dimen - 3) * 3);
            printf("%d", sc.moves);
        }
        else
        {
            gotoxy(box_y + 11, box_x + (dimen - 3) * 3);
            printf("Nill");
        }
        dimen++;
    }

    fclose(fp);
    back = 0;
    do
    {
        key = getkey();
        Beep(1500 * sound, 10);
        if (key == 13 && back == 1)
        {
            HomeScreen();
        }
        if (key == 9) //tab key
        {
            if (back == 0)
            {
                back = 1;
                boldbox(1, 1, " <-- ");
            }
            else
            {
                back = 0;
                smallbox(1, 1, " <-- ");
            }
        }
        else
        {
            smallbox(1, 1, " <-- ");
            back = 0;
        }

    } while (1);
}

void update_box_value(int ismain, int moves, int arr1[], int dimension, int x1, int y1)
{
    int i, j, k, t, lastbest;
    int win = 1;
    int size = dimension * dimension;
    int x2 = x2 + 2 * dimension, y2 = y1 + (5 * dimension);

    gotoxy(65 / 2, 1);
    printf("%d", moves);

    for (t = 1, i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++, t++)
        {
            gotoxy(y1 + 4 * j + j + 2, x1 + 2 * i + 1);

            if (arr1[t] != size)
                printf("%d", (arr1[t]));
            else
                printf("  ");
        }
    }

    for (i = 1; i < dimension * dimension; i++)
    {
        if (arr1[i] != i)
        {
            win = 0;
            break;
        }
    }

    if (win == 1 && ismain)
    {
        lastbest = PrevScore(moves, dimension);

        wingame(arr1, dimension, moves, lastbest);
    }
}
void draw_box(int dimension, int X1, int Y1, int box)
{

    int X2 = X1 + 2 * dimension, Y2 = Y1 + (5 * dimension), cur_pos = dimension * dimension;

    system("cls");

    int i, j;
    if (box == 1)
    {
        gotoxy(65 / 2 - 9, 1);
        printf("moves : ");
    }
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
            if ((j) % 5 == 0) //horizontal lines
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
}

int shuffle_box(int arr1[], int dimension, int x1, int y1)
{
    srand(time(0));
    int size = dimension * dimension;
    int cur_pos = size;

    int key, j = 0;
    do
    {
        int arrowkey[4] = {72, 80, 75, 77};
        key = arrowkey[rand() % 4];
        switch (key)
        {
        case 72: //upp arrow key
            if (!((cur_pos >= size - dimension + 1) && (cur_pos <= size)))
            {
                if ((cur_pos + dimension) >= 1 && (cur_pos + dimension) <= size)
                {
                    swap(&arr1[cur_pos + dimension], &arr1[cur_pos]);
                    cur_pos += dimension;
                    update_box_value(0, 0, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 80: //down arrow key
            if (!((cur_pos >= 1) && (cur_pos <= dimension)))
            {
                if ((cur_pos - dimension) >= 1 && (cur_pos - dimension) <= size)
                {
                    swap(&arr1[cur_pos - dimension], &arr1[cur_pos]);
                    cur_pos -= dimension;
                    update_box_value(0, 0, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 75: //left arrow key
            if ((cur_pos % dimension) != 0)
            {
                if (((cur_pos + 1) >= 1) && ((cur_pos + 1) <= size))
                {
                    swap(&arr1[cur_pos + 1], &arr1[cur_pos]);
                    cur_pos += 1;
                    update_box_value(0, 0, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 77: //right arrow key
            if ((cur_pos % dimension) != 1)
            {
                if (((cur_pos - 1) >= 1) && ((cur_pos - 1) <= size))
                {
                    swap(&arr1[cur_pos - 1], &arr1[cur_pos]);
                    cur_pos -= 1;
                    update_box_value(0, 0, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 27:
            break;
        }
        j++;
    } while (j < dimension * 100);
    return cur_pos;
}

void mainGame(int arr1[], int order)
{
    int key, i, j;
    int moves = 0;
    int dimension = order;
    int x1 = 8;
    int y1 = (65 - 5 * dimension) / 2;
    int ismain = 1;
    int cur_pos;
    int size = dimension * dimension;
    char options[][6] = {" <-- ", "Reset"};
    char *instructions[] = {"Instructions",
                            "UP Arrow key    : To move the numbered piece up ",
                            "Down Arrow key  : To move the numbered piece down ",
                            "Left Arrow key  : To move the numbered piece left ",
                            "Right Arrow key : To move the numbered piece right ",
                            "    <--         : takes you to the homescreen",
                            "    Reset       : will restart the game"};

    system("cls");

    draw_box(dimension, x1, y1, 1);
    box_value(arr1, dimension, x1, y1);

    // i = 0;
    i = -1;

    smallbox(1, 1, options[0]);
    smallbox(60, 1, options[1]);
    contentbox(6, 25, 62, 35, instructions, 7, 0);

    cur_pos = shuffle_box(arr1, dimension, x1, y1);

    do
    {

        key = getkey();
        Beep(1500 * sound, 10);
        Beep(1300 * sound, 50);
        switch (key)
        {
        case 72: //upp arrow key
            i = -1;
            smallbox(1, 1, options[0]);
            smallbox(60, 1, options[1]);
            if (!((cur_pos >= size - dimension + 1) && (cur_pos <= size)))
            {
                if ((cur_pos + dimension) >= 1 && (cur_pos + dimension) <= size)
                {
                    swap(&arr1[cur_pos + dimension], &arr1[cur_pos]);
                    cur_pos += dimension;
                    update_box_value(ismain, ++moves, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 80: //down arrow key
            i = -1;
            smallbox(1, 1, options[0]);
            smallbox(60, 1, options[1]);
            if (!((cur_pos >= 1) && (cur_pos <= dimension)))
            {
                if ((cur_pos - dimension) >= 1 && (cur_pos - dimension) <= size)
                {
                    swap(&arr1[cur_pos - dimension], &arr1[cur_pos]);
                    cur_pos -= dimension;
                    update_box_value(ismain, ++moves, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;
        case 75: //left arrow key
            i = -1;
            smallbox(1, 1, options[0]);
            smallbox(60, 1, options[1]);
            if ((cur_pos % dimension) != 0)
            {
                if (((cur_pos + 1) >= 1) && ((cur_pos + 1) <= size))
                {
                    swap(&arr1[cur_pos + 1], &arr1[cur_pos]);
                    cur_pos += 1;
                    update_box_value(ismain, ++moves, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;

        case 77: //right arrow key
            i = -1;
            smallbox(1, 1, options[0]);
            smallbox(60, 1, options[1]);
            if ((cur_pos % dimension) != 1)
            {
                if (((cur_pos - 1) >= 1) && ((cur_pos - 1) <= size))
                {
                    swap(&arr1[cur_pos - 1], &arr1[cur_pos]);
                    cur_pos -= 1;
                    update_box_value(ismain, ++moves, arr1, dimension, x1, y1);
                    break;
                }
            }
            break;
        case 9: //tab key
        {
            i++;
            if (i > 1)
                i = 0;
            if (i == 0)
            {
                boldbox(1, 1, options[0]);
                smallbox(60, 1, options[1]);
            }
            else if (i == 1)
            {
                smallbox(1, 1, options[0]);
                boldbox(60, 1, options[1]);
            }
        }
        break;
        case 13:
        {
            if (i == 0)
            {
                HomeScreen();
            }
            else if (i == 1)
            {
                for (j = 1; j <= 64; j++)
                {
                    arr1[j] = j;
                }
                mainGame(arr1, order);
            }
        }
        break;
        }

    } while (1);
}
void contentbox(int y1, int x1, int y2, int x2, char *content[], int lines, int clear)
{
    int i;
    if (clear == 1)
    {
        for (int r = x1; r <= x2; r++)
        {
            for (int c = y1; c <= y2; c++)
            {
                gotoxy(c, r);
                printf(" ");
            }
        }
    }
    gotoxy(y1, x1); // upper left corner
    printf("%c", 218);
    gotoxy(y2, x2); //lower right corner
    printf("%c", 217);
    gotoxy(y1, x2); // lower left corner
    printf("%c", 192);
    gotoxy(y2, x1); //upper right corner
    printf("%c", 191);
    for (i = y1 + 1; i < y2; i++) //upper horizontal lines
    {
        gotoxy(i, x1);
        printf("%c", 196);
    }

    for (i = y1 + 1; i < y2; i++) //lower horizontal lines
    {
        gotoxy(i, x2); //left vertical line
        printf("%c", 196);
    }

    for (i = x1 + 1; i < x2; i++) //left vertical line
    {
        gotoxy(y1, i);
        printf("%c", 179);
    }
    for (i = x1 + 1; i < x2; i++) //right vertical lines
    {
        gotoxy(y2, i);

        printf("%c", 179);
    }
    gotoxy(y1 + 1, x1);
    printf("%s", content[0]);

    for (i = 2; i <= lines; i++)
    {
        gotoxy(y1 + 2, x1 + i);
        printf("%s", content[i - 1]);
    }
}
void smallbox(int y, int x, char *str)
{
    int row, col, i;
    int len = strlen(str);
    gotoxy(y, x);
    printf("%s", str);
    row = x - 1;
    col = y - 1;
    gotoxy(col, row); // upper left corner
    printf("%c", 218);
    for (i = 1; i <= len; i++) //upper horizontal lines
    {
        gotoxy(col + i, row);
        printf("%c", 196);
    }

    gotoxy(col, row + 2); // lower left corner
    printf("%c", 192);
    for (i = 1; i <= len; i++) //lower horizontal lines
    {
        gotoxy(col + i, row + 2);
        printf("%c", 196);
    }
    gotoxy(col + len + 1, row); //upper right corner
    printf("%c", 191);
    gotoxy(col, row + 1); //left vertical line
    printf("%c", 179);
    gotoxy(col + len + 1, row + 2); //lower right corner
    printf("%c", 217);
    gotoxy(col + len + 1, row + 1); //right vertical line
    printf("%c", 179);
}
void boldbox(int y, int x, char *str)
{
    int row, col, i;
    int len = strlen(str);
    gotoxy(y, x);
    printf("%s", str);
    row = x - 1;
    col = y - 1;
    gotoxy(col, row); // upper left corner
    printf("%c", 213);
    for (i = 1; i <= len; i++) //upper horizontal lines
    {
        gotoxy(col + i, row);
        printf("%c", 205);
    }

    gotoxy(col, row + 2); // lower left corner
    printf("%c", 212);
    for (i = 1; i <= len; i++) //lower horizontal lines
    {
        gotoxy(col + i, row + 2);
        printf("%c", 205);
    }
    gotoxy(col + len + 1, row); //upper right corner
    printf("%c", 184);
    gotoxy(col, row + 1); //left vertical line
    printf("%c", 186);
    gotoxy(col + len + 1, row + 2); //lower right corner
    printf("%c", 190);
    gotoxy(col + len + 1, row + 1); //right vertical line
    printf("%c", 186);
}
void setcolor(int bg, int txt)
{
    char color[10] = "COLOR ";
    char ch[2];
    if (bg <= 9 && txt <= 9)
    {
        ch[0] = bg + '0';
        ch[1] = txt + '0';
    }
    else if (bg > 9 && txt <= 9)
    {
        ch[0] = bg + 55;
        ch[1] = txt + '0';
    }
    else if (bg <= 9 && txt > 9)
    {
        ch[0] = bg + '0';
        ch[1] = txt + 55;
    }
    else
    {
        ch[0] = bg + 55;
        ch[1] = txt + 55;
    }
    system(strncat(strncat(color, &ch[0], 1), &ch[1], 1));
}

void chooseColor()
{
    char color[][15] = {"  BLACK     ", "  BLUE      ", "  GREEN     ", "  AQUA      ", "  RED       ", "  PURPLE    ", "  YELLOW    ", "  WHITE     ", "  GRAY      ", " LIGHT BLUE ", " LIGHT GREEN", " LIGHT AQUA ", " LIGHT RED  ", "LIGHT PURPLE", "LIGHT YELLOW", "BRIGHT WHITE"};
    char *instruction[] = {"Instructions",
                           "* Use Tab, Up & Down Key for navigation",
                           "* Press Enter to change color",
                           "* Create your customized theme",
                           "* Dark Mode can also be generated"};

    int box_x = 12;
    int box_y = 20;
    int key, i = 0;
    static int bg_color = 0;
    static int txt_color = 7;
    system("cls");
    smallbox(1, 1, " <-- ");
    gotoxy(25, 5);
    printf("Choose Colour");
    smallbox(box_y, box_x, "BackGround");
    smallbox(box_y, box_x + 5, "  Text   ");

    boldbox(box_y + 20, box_x, color[bg_color]);
    smallbox(box_y + 20, box_x + 5, color[txt_color]);
    contentbox(6, 25, 62, 35, instruction, 5, 1);

    do
    {

        key = getkey();
        Beep(1500 * sound, 10);
        if (key == 9) //tab key
        {
            i++;
            if (i > 2)
                i = 0;
        }
        else if (key == 13 && i == 2) //back key
        {
            HomeScreen();
        }
        else if (key == 13 && i == 0)
        {
            bg_color++;
            if (bg_color > 15)
            {
                bg_color = 0;
            }
            if (bg_color != txt_color)
            {
                setcolor(bg_color, txt_color);
            }
            else
            {
                bg_color++;
                if (bg_color > 15)
                {
                    bg_color = 0;
                }
                setcolor(bg_color, txt_color);
            }
        }
        else if (key == 13 && i == 1)
        {
            txt_color++;
            if (txt_color > 15)
            {
                txt_color = 0;
            }
            if (bg_color != txt_color)
            {
                setcolor(bg_color, txt_color);
            }
            else
            {
                txt_color++;
                if (txt_color > 15)
                {
                    txt_color = 0;
                }
                setcolor(bg_color, txt_color);
            }
        }
        else if (key == 72) // up arrow key
        {
            i--;
            if (i < 0)
            {
                i = 1;
            }
        }
        else if (key == 80) // down arrow key
        {
            i++;
            if (i > 1)
            {
                i = 0;
            }
        }
        if (i == 0)
        {
            boldbox(box_y + 20, box_x, color[bg_color]);
            smallbox(box_y + 20, box_x + 5, color[txt_color]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 1)
        {
            boldbox(box_y + 20, box_x + 5, color[txt_color]);
            smallbox(box_y + 20, box_x, color[bg_color]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 2)
        {
            smallbox(box_y + 20, box_x + 5, color[txt_color]);
            smallbox(box_y + 20, box_x, color[bg_color]);
            boldbox(1, 1, " <-- ");
        }
    } while (1);
}
int chooseDimension()
{

    char dimension[][10] = {"  3 X 3  ", "  4 X 4  ", "  5 X 5  ", "  6 X 6  ", "  7 X 7  ", "  8 X 8  "};
    char *about[] = {"Different Levels",
                     "3x3 :  Beginners",
                     "4x4 :  Classix",
                     "5x5 :  Smart",
                     "6x6 :  Challenger",
                     "7x7 :  Expert",
                     "8x8 :  Master"};
    int box_x = 7;
    int box_y = 27;
    int key, i = 0;
    system("cls");
    smallbox(1, 1, " <-- ");
    gotoxy(25, 5);
    printf("Choose Dimension");
    boldbox(box_y, box_x, dimension[0]);
    smallbox(box_y, box_x + 3, dimension[1]);
    smallbox(box_y, box_x + 6, dimension[2]);
    smallbox(box_y, box_x + 9, dimension[3]);
    smallbox(box_y, box_x + 12, dimension[4]);
    smallbox(box_y, box_x + 15, dimension[5]);
    contentbox(6, 25, 62, 35, about, 7, 0);
    do
    {
        key = getkey();
        Beep(1500 * sound, 10);

        if (key == 13 && i == 6)
        {
            HomeScreen();
        }
        else if (key == 13)
        {
            return i + 3;
        }
        if (key == 9) //tab key
        {
            i++;
            if (i > 6)
                i = 0;
        }
        else if (key == 72) // up arrow key
        {
            i--;
            if (i < 0)
            {
                i = 5;
            }
        }
        else if (key == 80) // down arrow key
        {
            i++;
            if (i > 5)
            {
                i = 0;
            }
        }
        if (i == 0)
        {
            boldbox(box_y, box_x, dimension[i]);
            smallbox(box_y, box_x + 3, dimension[1]);
            smallbox(box_y, box_x + 6, dimension[2]);
            smallbox(box_y, box_x + 9, dimension[3]);
            smallbox(box_y, box_x + 12, dimension[4]);
            smallbox(box_y, box_x + 15, dimension[5]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 1)
        {
            smallbox(box_y, box_x + 0, dimension[0]);
            boldbox(box_y, box_x + 3, dimension[i]);
            smallbox(box_y, box_x + 6, dimension[2]);
            smallbox(box_y, box_x + 9, dimension[3]);
            smallbox(box_y, box_x + 12, dimension[4]);
            smallbox(box_y, box_x + 15, dimension[5]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 2)
        {
            smallbox(box_y, box_x + 0, dimension[0]);
            smallbox(box_y, box_x + 3, dimension[1]);
            boldbox(box_y, box_x + 6, dimension[i]);
            smallbox(box_y, box_x + 9, dimension[3]);
            smallbox(box_y, box_x + 12, dimension[4]);
            smallbox(box_y, box_x + 15, dimension[5]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 3)
        {
            smallbox(box_y, box_x + 0, dimension[0]);
            smallbox(box_y, box_x + 3, dimension[1]);
            smallbox(box_y, box_x + 6, dimension[2]);
            boldbox(box_y, box_x + 9, dimension[i]);
            smallbox(box_y, box_x + 12, dimension[4]);
            smallbox(box_y, box_x + 15, dimension[5]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 4)
        {
            smallbox(box_y, box_x + 0, dimension[0]);
            smallbox(box_y, box_x + 3, dimension[1]);
            smallbox(box_y, box_x + 6, dimension[2]);
            smallbox(box_y, box_x + 9, dimension[3]);
            boldbox(box_y, box_x + 12, dimension[i]);
            smallbox(box_y, box_x + 15, dimension[5]);
            smallbox(1, 1, " <-- ");
        }
        else if (i == 5)
        {
            smallbox(box_y, box_x + 0, dimension[0]);
            smallbox(box_y, box_x + 3, dimension[1]);
            smallbox(box_y, box_x + 6, dimension[2]);
            smallbox(box_y, box_x + 9, dimension[3]);
            smallbox(box_y, box_x + 12, dimension[4]);
            boldbox(box_y, box_x + 15, dimension[i]);
            smallbox(1, 1, " <-- ");
        }
        else
        {
            boldbox(1, 1, " <-- ");
            smallbox(box_y, box_x + 0, dimension[0]);
            smallbox(box_y, box_x + 3, dimension[1]);
            smallbox(box_y, box_x + 6, dimension[2]);
            smallbox(box_y, box_x + 9, dimension[3]);
            smallbox(box_y, box_x + 12, dimension[4]);
            smallbox(box_y, box_x + 15, dimension[5]);
        }
    } while (1);
}

void HomeScreen()
{
    int key = 7;
    int arr1[65];
    int c_x = 6;
    int c_y = 24;
    int x1 = 8;
    int y1 = 24;
    int dimension = 3;
    char options[][10] = {"New Game ", "  Color  ", "Sound ON ", " Scores  "};
    int box_x = 18;
    int box_y = 7;
    int i, y;
    int color = 0;
    char *about[] = {"About this game:",
                     "Number Puzzle is a sliding puzzle that consists of a ",
                     "frame of numbered square blocks in random order with ",
                     "oneblock missing. The objective of the puzzle is to",
                     "place the blocks in order by making sliding moves ",
                     "that uses the empty space."};
    for (i = 1; i <= 64; i++)
    {
        arr1[i] = i;
    }
    draw_box(4, c_x, c_y, 0);
    box_value(arr1, 4, c_x, c_y);
    gotoxy(c_y + 2, c_x - 2);
    printf("NUMBER PUZZLE GAME\n");
    i = 0;
    y = 0;
    boldbox(box_y + y, box_x, options[0]);
    smallbox(box_y + 15, box_x, options[1]);
    if (sound == 1)
    {
        strcpy(options[2], "Sound ON ");

        smallbox(box_y + 30, box_x, options[2]);
    }
    else
    {
        strcpy(options[2], "Sound OFF");
        smallbox(box_y + 30, box_x, options[2]);
    }
    smallbox(box_y + 45, box_x, options[3]);
    contentbox(6, 25, 62, 35, about, 5, 0);
    do
    {
        key = getkey();
        Beep(1500 * sound, 10);

        if (key == 13 && i == 0)
        {
            dimension = chooseDimension();
            mainGame(arr1, dimension);
        }
        else if (key == 13 && i == 2) //enter key
        {
            if (sound == 1)
            {
                strcpy(options[2], "Sound OFF");
                sound = 0;
                boldbox(box_y + 30, box_x, options[2]);
            }
            else if (sound == 0)
            {
                strcpy(options[2], "Sound ON ");

                sound = 1;
                boldbox(box_y + 30, box_x, options[2]);
            }
        }
        else if (key == 13 && i == 1)
        {
            chooseColor();
        }
        else if (key == 13 && i == 3)
        {
            DisplayScore();
        }
        if (key == 77) //right arrow key
            i++;
        else if (key == 75) //left arrow key
            i--;
        else if (key == 9)
            i++;
        if (i > 3)
            i = 0;
        if (i < 0)
            i = 3;
        if (i == 0)
        {
            boldbox(box_y + 0, box_x, options[i]);
            smallbox(box_y + 15, box_x, options[1]);
            smallbox(box_y + 30, box_x, options[2]);
            smallbox(box_y + 45, box_x, options[3]);
        }
        else if (i == 1)
        {
            smallbox(box_y + 0, box_x, options[0]);
            boldbox(box_y + 15, box_x, options[i]);
            smallbox(box_y + 30, box_x, options[2]);
            smallbox(box_y + 45, box_x, options[3]);
        }
        else if (i == 2)
        {
            smallbox(box_y + 0, box_x, options[0]);
            smallbox(box_y + 15, box_x, options[1]);
            boldbox(box_y + 30, box_x, options[i]);
            smallbox(box_y + 45, box_x, options[3]);
        }
        else
        {
            smallbox(box_y + 0, box_x, options[0]);
            smallbox(box_y + 15, box_x, options[1]);
            smallbox(box_y + 30, box_x, options[2]);
            boldbox(box_y + 45, box_x, options[i]);
        }
    } while (1);
}
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
int main()
{
    hideCursor();
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("PUZZLE GAME");
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
