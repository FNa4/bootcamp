#include <stdio.h>
int main () {
    int a = 0;

    while (a <= 1000) {
       printf ("%d\n", a);
       a = a + 11;
    }

    printf ("The loop has ended.");

    return 0;
}