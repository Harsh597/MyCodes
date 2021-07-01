#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Part1
void main()
{
    #ifndef Part1
    int year;
    int extra_day;
    printf("\nProgram to find the day");
    printf("\nEnter any year\n");
    scanf("%d",&year);
    extra_day= (year-1900)+((int)(year-1900)/4)-((int)(year-1900)/100)+((int)(year-1900)/400);
    printf("Extraday=%d",extra_day);
    switch (extra_day % 7)
    {
    case 0: 
            printf("\nMonday");
             break;
    case 1: 
            printf("\ntuesday");

             break;
    case 2: 
            printf("\nWednesday");

             break;
    case 3: 
            printf("\nThursday");

             break;
    case 4: 
            printf("\nFriday");

             break;
    case 5: 
            printf("\nSaturday");

             break;
    case 6: 
            printf("\nSunday");

             break;
    
    default:
            printf("\nInvalid Entry");
             break;
    }
    

      #else
      int leapdays, firstday, yr;
      long int normaldays,totaldays;

      printf("Enter year");
      scanf("%d",&yr);

      normaldays=(yr-1900)*365L;
      leapdays=(yr-1900)/4-(yr-1900)/100+(yr-1900)/400;

      totaldays=normaldays+leapdays;
      firstday=totaldays%7;

      if(firstday==0)
        printf("\nMonday");

      if(firstday==1)
        printf("\nMonday");

      if(firstday==2)
        printf("\nTuesday");

      if(firstday==3)
        printf("\nThursday");

      if(firstday==4)
        printf("\nFriday");

      if(firstday==5)
        printf("\nSaturday");

      if(firstday==6)
        printf("\nSunday");

        printf("\n\n\n\nPress any key to exit...");
        getch();
        

     #endif       
}