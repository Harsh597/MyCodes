#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char *p = "Hello";       /* pointer is variable, so is string */
    *p = 'M';                /* works */
    p = "Bye";               /* works */
    const char *q = "Hello"; /* string is fixed pointer is not */
    //*q = 'M' ; /* error */
    q = "Bye";               /* works */
    char const *s = "Hello"; /* string is fixed pointer is not */
    //*s = 'M' ; /* error */
    s = "Bye";               /* works */
    char *const t = "Hello"; /* pointer is fixed string is not */
    *t = 'M';                /* works */
    //t = "Bye" ; /* error */
    const char *const u = "Hello"; /* string is fixed so is pointer */
    //*u = 'M' ; /* error */
    //u = "Bye" ; /* error */
}