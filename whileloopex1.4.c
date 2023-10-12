#include <stdio.h>
int main () {
    int a = 100;

    while (a <= 100 && a >= 0) {
        printf ("%d\n", a);
        a = a - 5;
    }

    printf ("The loop has ended.");

    return 0;
}