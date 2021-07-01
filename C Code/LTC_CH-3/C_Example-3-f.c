#include <stdio.h>
#include <conio.h>
//#define Method1
void main()
{
#ifndef Method1
    char ch_i = 65,ch_d=70,ch_d1=70;
    printf("\nProgram to print the pattern");
    for (int i = 0; i <=6; i++)
    { printf("\n");
    ch_i=65;
    ch_d=ch_d1;
        for (int j = 1; j <= 7 - i; j++)
        {
            printf(" %c", ch_i);
            ch_i++;
        }
        for (int l = 1; l <=(2*i)-1; l++)
            printf("  ");

        for (int k = 1; k <=7-i; k++)
        {
            if(ch_d>='A')
            printf(" %c", ch_d);
            ch_d--;
        }
        if(i>=1)
        ch_d1--;
    }
#else
    int i = 1, x = 71, blanks = 0, j, val, k;
    while (i <= 7)
    {
        j = 65;
        val = x;
        while (j <= val)
        {
            printf("%c", j);
            j++;
        }

        if (i == 1)
            val--;

        k = 1;

        while (k <= blanks)
        {
            printf(" ");
            k++;
        }
        blanks = 2 * i - 1;

        while (val >= 65)
        {
            printf("%c", val);
            val--;
        }
        printf("\n");
        x--;
        i++;
    }
#endif
}