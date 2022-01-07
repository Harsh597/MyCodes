#include <stdio.h>
int fib(int n)
{
    if(n==1)
    return 0;
    else if(n==2)
    return 1;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    printf("\nEnter the value of n\n");
    scanf("%d", &n);
   if(n==1)
   printf("0 ");
   else if(n==2)
    printf("1 ");
    else
    {
        printf("0 1 ");
        for(int i=3;i<=n;i++)
        printf("%d ",fib(i));
    }
    //     int a=0;
    //     int b=1;
    //     int c,i,n;
    //     printf("\nEnter the value of n\n");
    //     scanf("%d",&n);
    //     if(n>=1)
    //    {
    //        printf("%d ",a);
    //         for(int i=1;i<n;i++)
    //         {
    //             printf("%d ",b);
    //             c=a+b;
    //             a=b;
    //             b=c;
    //         }
    //    }

    return 0;
}