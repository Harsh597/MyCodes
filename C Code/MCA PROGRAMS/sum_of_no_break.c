#include <stdio.h>
void main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += i;

        if (i == 4)
            break;
    }
    printf("\n%d", sum);
}