#include <stdio.h>
#include <conio.h>
void main()
{
    int num,temp;
    printf("\nProgram to print the prime numbers ");
    printf("\nEnter the max number");
    scanf("%d", &num);
    printf("\nPrime numbers between 1 and %d is 1",num);
    for (int i = 2; i < num; i++)
    {
        temp=0;
        for (int j = 2 ; j<=i/2  ; j++)
        {
            if(i%j==0)
           {
                temp++;
                break;
           }
        }

        if(temp==0)
        printf("\n%d",i);
        
    }
    
}