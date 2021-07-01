#include<stdio.h>
#include<conio.h>
#include<math.h>

 
 void main()
 {
     int num,sum,temp=0;
     printf("Program to reverse a five digit number\n\n");
     printf("\nEnter any five digit number\n");
     scanf("%d",&num);
      for(int i=1,j=4;i<=5;i++,j--)
    {
       sum=(num % (int)powf(10,i))/pow(10,i-1)+1;
       if(sum==10)
       sum=0;
       temp+=sum*powf(10,i-1);
       printf("\n%d",temp);
    

        
    }

    printf("\nReversed NO-- of %d ",temp);

 }