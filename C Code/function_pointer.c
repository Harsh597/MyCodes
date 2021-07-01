#include <stdio.h>
float fun1(int, int);
float fun2(int, int);
float fun3(int, int);
float fun4(int, int);

int main()
{
    float (*f[4])(int, int);
    f[0] = fun1;
    f[1] = fun2;
    f[2] = fun3;
    f[3] = fun4;
    int m = 2, n = 6;
    for (int i = 0; i <= 3; i++)
    {
        printf("returned value %f ", f[i](m++, n++));
    }

    return 0;
}
float fun1(int i, int j)
{
    printf(" \nfun 1 %d %d\n", i, j);
    return (float)i / j;
}
float fun4(int i, int j)
{
    printf(" \nfun 4 %d %d\n", i, j);
    return (float)i / j;
}
float fun2(int i, int j)
{
    printf(" \nfun 2 %d %d\n", i, j);
    return (float)i / j;
}
float fun3(int i, int j)
{
    printf(" \nfun 3 %d %d\n", i, j);
    return (float)i / j;
}