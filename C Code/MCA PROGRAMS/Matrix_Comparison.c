#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define MAX 128

void display(int n,int mat[][n])
{
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d",mat[i][j]);
        }
        printf("\n");
    }
}

void strassenMul(int n,int mat1[][n],int mat2[][n])
{
    if(n==2)
    {
        int mat3[2][2];
        int a=mat1[0][0];
        int b=mat1[0][1];
        int c=mat1[1][0];
        int d=mat1[1][1];
        int e=mat2[0][0];
        int f=mat2[0][1];
        int g=mat2[1][0];
        int h=mat2[1][1];
        int p1=(a*f)-(a*h);
        int p2=(a*h)+(b*h);
        int p3=(c*e) +(d*e);
        int p4=(d*g)-(d*e);
        int p5=(a+d)*(e+h);
        int p6=(b-d)*(g+h);
        int p7=(a-c)*(e+f);

        mat3[0][0]=p5+p4-p2+p6;
        mat3[0][1]=p1+p2;
        mat3[1][0]=p3+p4;
        mat3[1][1]=p1+p5-p3-p7;
    }
    else
    {
        n/=2;
        

    }
}

void normalMul(int n,int mat1[][n],int mat2[][n])
{
    int mat3[n][n];
    display(n,mat1);
    printf("\n\n");
    display(n,mat2);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat3[i][j]=0;
            for(int k=0;k<n;k++)
            {
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
                
            }
        }
    }
    printf("\n\n");
    display(n,mat3);
   
}
int main()
{
    int n=16;
    int mat1[n][n];
    int mat2[n][n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat1[i][j]=rand()%8;
            mat2[i][j]=rand()%10;
        }
    }

    normalMul(n,mat1,mat2);
    return 0;
}