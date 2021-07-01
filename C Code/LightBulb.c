#include <stdio.h>
#include <string.h>
typedef enum Status
{
    ON,
    OFF
} State;
typedef enum BulbColor
{
    Yellow = 1,
    Red = 2,
    Blue = 3
} Color;
struct LightBulb
{
    State st;
    Color col;
    int power;
    char type[20];

} LB;
void bulbInfo()
{
    printf("\nBulb Status: %d", LB.st);
    printf("\nBulb Colour: %d", LB.col);
    printf("\nBulb Power: %d", LB.power);
    printf("\nBulb type: %s", LB.type);
}
int main()
{
    LB.st = ON;
    LB.col = Red;
    LB.power = 120;
    strcpy(LB.type, "LED");

    bulbInfo();
    return 0;
}