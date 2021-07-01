#include<stdio.h>
#include<conio.h>

void main(){
int a,b;

printf("Program to swap two numbers\n");
printf("Enter any two numbers");
scanf("%d%d",&a,&b);
printf("\nYou have entered a =%d and b =%d",a,b);
printf("\n********************After Swapping********************");
b=a+b-(a=b);
printf("\nThe value is a =%d and b =%d",a,b);




}