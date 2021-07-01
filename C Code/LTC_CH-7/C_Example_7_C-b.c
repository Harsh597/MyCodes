#include <stdio.h>
#include <conio.h>
#include "MyLibrary.c"
void main()
{
    printf("\nProgram to find the area of square , circle and triangle using the macro definition");
    printf("\nArea of Square  of side 5 is= %d", AREA_SQUARE(5));
    printf("\nArea of Circle  of radius 7 is= %f", AREA_CIRCLE(1));
    printf("\nArea of Triangle with length =10 and breadth =2 is= %d", AREA_TRIANGLE(10, 2));
    printf("\nAbsolute value of the -5 is %d", ABS(-5));
    printf("\nLower case equivalent  of A is %c", TO_LOWER('A'));
}