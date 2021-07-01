#include <stdio.h>
#include <stdarg.h>
void display_shapes(int no, ...);
void display_shapes(int no, ...)
{
    va_list ptr;

    va_start(ptr, no);

    switch (no)
    {
    case 1:
        printf("\nDisplay Point (x,y)");
        for (int i = 0; i < 2; i++)
            printf("%d ", va_arg(ptr, int));

        break;
    case 2:
        printf("\nDisplay line (x1,y1) to (x2,y2)");
        // for (int i = 0; i < 2; i++)
        //     va_arg(ptr, int);
        for (int i = 0; i < 4; i++)
            printf("%d ", va_arg(ptr, int));

        break;
    case 3:
        printf("\nDisplay Triangle (x1,y1) ,(x2,y2) & (x3,y3) ");
        // for (int i = 0; i < 6; i++)
        //     va_arg(ptr, int);
        for (int i = 0; i < 6; i++)
            printf("%d ", va_arg(ptr, int));

        break;

    default:
        printf("\nGalat NO. of arguements\n");
        break;
    }
}
int main()
{
    void (*shapes)(int, ...);
    shapes = display_shapes;
    shapes(3, 0, 0, 5, 5, 6, 7);
    return 0;
}