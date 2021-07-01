#include<stdio.h>
#include<conio.h>
void main()
{
    int ch;
    puts("\nHit any key...");
    ch=getkey();
    printf("\nPress any key to exit...\n");
    getch();
  
}
int getkey()
{
    int ascii,scan;
   // while(!kbhit())
    ascii=getch();

    if(ascii==0)
    {
        scan=getch();
        printf("\nYou hit a special key of scancode %d",scan);

    }
    else
        printf("\nYou hit a ordinary key of ascii value %d",ascii);
}
