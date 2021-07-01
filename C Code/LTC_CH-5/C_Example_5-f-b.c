#include<stdio.h>
#include<conio.h>
#include<math.h>
void calculate(int*,float*,float*);
void main()
{
    int sum;
    float avg,sdv;
    printf("Program to return the average,sum and standard deviation through function\n");
    calculate(&sum,&avg,&sdv);
    printf("\nsum is %d\n Average is %f\nStandard Deviation is %f",sum,avg,sdv);
    
}
void calculate(int* sum,float*avg,float*sdv)
{
    int n1,n2,n3,n4,n5;
    printf("Enter the value of the 5  integers\n");
    scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);
    *sum=n1+n2+n3+n4+n5;
    *avg=(*sum)/5;
    *sdv=sqrt(pow((n1-*avg),2)+pow((n2-*avg),2)+pow((n3-*avg),2)+pow((n4-*avg),2)+pow((n5-*avg),2));
}