#include <stdio.h>
#include <conio.h>
void main()
{
    int range, sum = 0, start, end, i;
    printf("\nProgram to find the sum of n numbers \n");
    printf("Entet the starting number \n");
    scanf("%d", &start);
    printf("Entet the ending number \n");
    scanf("%d", &end);

    i = start;
    do
    {
        sum += i;

        i++;
    } while (i <= end);

    printf("\nThe sum of the numbers from %d to %d is %d", start, end, sum);
}
