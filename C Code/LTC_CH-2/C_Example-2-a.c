#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
    int cp,sp;
    float result;

    printf("*****************Program to check whether Profit or Loss is incurred*****************");

    printf("\nEnter the Cost Price of the Article\n");
    scanf("%d",&cp);
    printf("\nEnter the Selling  Price of the Article\n");
    scanf("%d",&sp);
    result=((sp-cp)*100)/cp;
       if (result>0)
        printf("\nCongrats! you have a profit of %f percent",result);
       else if (result<0)
        printf("\nSad! you have a Loss of %f percent",(-1)*result);
       else
        printf("\nNo Profit No Loss");

    


}