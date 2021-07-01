#include <stdio.h>
#include <conio.h>
#include <string.h>
void setcolor(int bg, int txt)
{
    char color[10] = "color ";
    char buf[10];
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
    system( strncat(strncat(color, &ch[0], 1), &ch[1], 1));
}

int main()
{
    setcolor(13, 5);
    return 0;
}