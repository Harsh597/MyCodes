#include <stdio.h>
#include <conio.h>
#include<math.h>

//#define Method1
void main()
{
#ifndef Method1

    int num = 1, count, limit;
    float sum = 0.0, fact;

    printf("Enter the number of terms\n");
    scanf("%d", &limit);

    while (num <= limit)
    {
        fact = 1;
        for (count = 1; count <= num; count++)
        {
            fact = fact * count;
        }

        sum = sum + (num / fact);

        num++;
    }

    printf("Sum of %d terms of series is %f\n", limit, sum);

    //Method 2//s

#else
    int n, i;
    float sum = 0.0,fact;
    printf("Enter the number of terms\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        fact = 1;
        for (int j = 0; j <= i; j++)
        {   if(j>=1)
            fact = fact * (j);
           
        }

        sum=sum+(1/fact);
    }

    printf("Sum of %d terms of series is %f\n", n, sum);
#endif
}