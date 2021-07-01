#include<stdio.h>
#include<conio.h>
void main()
{
    int n=0;
    printf("\nProgram to print the pattern\n");

    for (int i = 0; i < 7; i++)
    { printf("\n");
        for (int j = 0; j < 7-i; j++)
        {
            printf("  ");
        }
        for (int k = 0; k <i; k++)
        {
            printf("%4d",++n);
        }
        
        
    }
    

}