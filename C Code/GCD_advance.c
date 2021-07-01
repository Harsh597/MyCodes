#include <stdio.h>
#include <conio.h>
int gcd_euclid(int, int);
void main()
{
    int n1, n2;
    printf("\nProgram to find the gcd using euclids algorithm");
    printf("\nEnter the two number\n");
    scanf("%d %d", &n1, &n2);

    printf("\nGCD of  %d and %d is %d", n1, n2, gcd_euclid(n1, n2));
}
int gcd_euclid(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        gcd_euclid(n2, n1 % n2);
}