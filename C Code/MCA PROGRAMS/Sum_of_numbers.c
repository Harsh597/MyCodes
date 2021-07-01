#include <stdio.h>
#include <conio.h>
void main()
{
    int range, sum = 0, start, end;
    printf("\nProgram to find the sum of n numbers \n");
    printf("Entet the starting number \n");
    scanf("%d", &start);
    printf("Entet the ending number \n");
    scanf("%d", &end);
    for (int i = start; i <= end; i++)
    {
        sum += i;
    }

    printf("\nThe sum of the numbers from %d to %d is %d", start, end, sum);
}
