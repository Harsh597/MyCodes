#include <stdio.h>
void main()
{
    int start, end, num;
    int flag;
    printf("Program to print the prime numbers between the range \n");
    printf("\nEnter the starting no.\n");
    scanf("%d", &start);
    printf("\nEnter the last no.\n");
    scanf("%d", &end);
    for (num = start; num <= end; num++)
    {
        flag = 0;
        for (int i = 2; i < num / 2 + 1; i++)
        {
            if (num % i == 0)
                flag = 1;
        }
        if (flag == 0)
            printf("\n%d", num);
    }
}