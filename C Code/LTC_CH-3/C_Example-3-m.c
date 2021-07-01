#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    float result=0,x,t;
    printf("\nProgram of Natural Logarithm");
    printf("\nEnter the value\n");
    scanf("%f",&x);
    t=(x-1)/x;

    for (int i = 1; i <= 17; i++)
    {
        result=result+(pow(1,t))/i;
    }
        printf("\nFinal Result =  %.12f",result);

    

}