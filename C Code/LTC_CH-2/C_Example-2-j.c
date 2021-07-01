#include<stdio.h>
#include<conio.h>
struct point
{
    int x;
    int y;
}p[3];

void main()
{
    int result;
    printf("\nProgram to check if three points lie on a line or not?");
    for (int i = 0,j=0; i < 3;i++ ,j++)
    {
        printf("\nEnter the point no %d \n",j+1);
        scanf("%d %d",&p[i].x,&p[i].y);
    }

    result=((p[0].x-p[1].x)*(p[1].y-p[2].y))-((p[1].x-p[2].x)*(p[0].y-p[1].y));
    
    if(result==0)
        printf("\nThree points are collinear");
    else
        printf("\nThree points are not collinear");

    
   
}