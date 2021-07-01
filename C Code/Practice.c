#include<stdio.h>
#include<math.h>

void main (){

    int i,num;
    int sum=0;
   printf("Enter any five digit number\n");
    scanf("%d",&num);
    
    for(int i=1;i<=5;i=i+1)
    {
        sum+=(num % (int)powf(10,i))/pow(10,i-1);
        printf("\n%d",sum);
    }
    printf("\nSum of all the digits of %d ",sum);

}