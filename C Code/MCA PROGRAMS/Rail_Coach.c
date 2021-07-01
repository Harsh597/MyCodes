#include <stdio.h>
void main()
{
    int seat, birth;

    printf("Program to check for the validity of seat number and print its position\n");
    printf("Enter the Seat Number ");
    scanf("%d", &seat);
    if (seat >= 1 && seat <= 72)
    {
        birth = seat % 8;
        switch (birth)
        {
        case 1:
            printf("\nThis seat number belongs Lower Birth");
            break;
        case 4:
            printf("\nThis seat number belongs Lower Birth");
            break;
        case 2:
            printf("\nThis seat number belongs Middle Birth");
            break;
        case 5:
            printf("\nThis seat number belongs Middle Birth");
            break;
        case 3:
            printf("\nThis seat number belongs Upper Birth");
            break;
        case 6:
            printf("\nThis seat number belongs Upper Birth");
            break;
        case 7:
            printf("\nThis seat number belongs Side Lower Birth");
            break;
        case 0:
            printf("\nThis seat number belongs Side Upper Birth");
            break;
        }
    }
    else
        printf("\n!!This is Invalid Seat");
}