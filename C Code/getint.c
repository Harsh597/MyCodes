#include <stdio.h>
#include <string.h>
int getint();
void main()
{
  int a;
  printf("\nEnter a numeric string\n");
  a=getint();
  printf("\nYou entered %d",a);
}
int getint()
{
    char str[6];
    int i,j,k,val;
    i=0;
    while(i<=5)
    {
        str[i]=getche();
        if(str[i]=='\r')
        {
            str[i]='\0';
            break;
        }
         if(str[i]=='\b')
        {
            i--;
           printf("\b");
        }
        else 
            i++;
    }
        val=0;
        k=1;
        for ( j = i-1; j >= 0; j--)
        {
            val+=(str[j]-48 )*k;
            k*=10;
        }
        
    return val;

}
