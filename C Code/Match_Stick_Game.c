//Let us C Example 3.f
#include<conio.h>
#include<stdio.h>
void main()
{
    int m=21,p,c;
    printf("\n***********************Match Stick Game***********************");
    while(1)
    {
        printf("\nNo. of matches left = %d",m);
        printf("\nPick up 1 2 3 or 4 matches");
        scanf("%d",&p);
        if(p>4 ||p<1)
        continue;
        m=m-p;
        printf("\nNo. of matches left = %d",m);
        c=5-p;
        printf("\nOut of which computer picked up %d",c);
        m=m-c;
        if(m==1)
        {
        printf("\nNo. of matches left = %d",m);
        printf("\nYou lost the game");
        break;
        }
    }
}
