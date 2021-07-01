#include<stdio.h>
#include<conio.h>
// int fact(int);
// void main()
// {
//     int num;

//     printf("\nProgram to find the factorial of a number");
//     printf("\n Enter the number\t");
//     scanf("%d",&num);
//     printf("\nfactorial of the %d is  %d",num,fact(num));

   

// }
int fact(int num)
{
     
    int fact=1;
    int i=1;

    while(i<=num)
    {
        fact=fact*i;
        i++;
    }   
    
    return fact;
}