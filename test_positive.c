#include <stdio.h>
int main () {
    int a;

    printf ("Please enter an integer: ");
    scanf ("%d", &a);

    if (a < 0) {
        printf ("%d is negative.\n", a);   
    }
    else if (a == 0) {
        printf ("%d is neither positive nor negative.\n", a);
    }
    else {
        printf ("%d is positive.\n", a);
    }

    return 0;
}