#include <graphics.h>
int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";

    initgraph(&gd, &gm, data);
    circle(200, 200, 100);
    getch();
    closegraph();

    return 0;
}