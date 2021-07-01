#include<stdio.h>
#include<conio.h>
void main()
{
    int n;
    printf("\nProgram to print the table of the number entered by the user");
    printf("\nEnter the number\n");
    scanf("%d",&n);

    for (int i = 1; i <= 10; i++)
    {
       printf("\n %d * %d =  %d",n,i,n*i);
    }
    
}