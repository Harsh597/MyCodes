#include <stdio.h>
void main()
{
    char ch = 'y';
    int num;
    int i = 0;
    int min = 2147483647;
    int max = -2147483648;
    int sum = 0;
    printf("\nProgram to count the numbers and find the min and max from them");
    do
    {
        printf("\nEnter any number \n");

        scanf("%d", &num);
        sum += num;
        if (num < min)
            min = num;
        if (num > max)
            max = num;
        i++;
        fflush(stdin);


        printf("\nWant to enter more number y/n?   ");
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("\nYou have enterd %d numbers", i);
    printf("\nMaximum  is %d", max);
    printf("\nMinimum  is %d", min);
    printf("\nSum of All %d number is %d", i, sum);
}
