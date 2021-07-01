#include<stdio.h>
#include<conio.h>
#include<math.h>
struct circle
{
    int h,k;
    int radius;
}c={0,0,2};

void main()
{
    int x,y;
    float distance;
    printf("\nProgram to find whether a point lies inside , outside or on the circle\n");
    printf("\nThe given circle is \n (x-%d)^2+(y-%d)^2=%.1f",c.h,c.k,powf(c.radius,2));
    printf("\nNow the enter the point you want to check\n");
    scanf("%d%d",&x,&y);
    
     distance=sqrt((powf((x-c.h),2))+(powf((y-c.k),2)));
     if(distance==c.radius)
        {
            printf("\nPoint lies on the circle");
        }
     else if (distance>c.radius)
     {
            printf("\nPoint lies outside the circle");
        
     }
     else
            printf("\nPoint lies inside the circle");
            
}