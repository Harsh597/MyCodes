#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
    int amnt;
    int no_of_notes_of_2000,no_of_notes_of_500,no_of_notes_of_200,no_of_notes_of_100,no_of_notes_of_50;
    int no_of_notes_of_20,no_of_notes_of_10,no_of_notes_of_5,no_of_coins_of_2,no_of_coins_of_1;
    printf("**************Welcome to HarshG's ATM**************\n\n");
    printf("How much Amount you want?\n");
    scanf("%d",&amnt);
   
    switch (1)
    {
    case 1:
            no_of_notes_of_2000= amnt/2000;
            amnt%=2000;
            printf("No of 2000 notes %d\n",no_of_notes_of_2000);
    case 2:
            no_of_notes_of_500= amnt/500;
            amnt%=500;
            printf("No of 500 notes %d\n",no_of_notes_of_500);

    case 3:
            no_of_notes_of_200= amnt/200;
            amnt%=200;
            printf("No of 200 notes %d\n",no_of_notes_of_200);

    case 4:
            no_of_notes_of_100= amnt/100;
            amnt%=100;
            printf("No of 100 notes %d\n",no_of_notes_of_100);
            
    case 5:
            no_of_notes_of_50= amnt/50;
            amnt%=50;
            printf("No of 50 notes %d\n",no_of_notes_of_50);

    case 6:
            no_of_notes_of_20= amnt/20;
            amnt%=20;
            printf("No of 20 notes %d\n",no_of_notes_of_20);

    case 7:
            no_of_notes_of_10= amnt/10;
            amnt%=10;
            printf("No of 10 notes %d\n",no_of_notes_of_10);

    case 8:
            no_of_notes_of_5= amnt/5;
            amnt%=5;
            printf("No of 5 notes %d\n",no_of_notes_of_5);      
            
    case 9:
            no_of_coins_of_2= amnt/2;
            amnt%=2;
            printf("No of 2 coins %d\n",no_of_coins_of_2);   

    case 10:
            no_of_coins_of_1= amnt/1;
            amnt%=1;
            printf("No of 1 coins %d\n",no_of_coins_of_1);   
                  
    default:
        break;
    }

   

}