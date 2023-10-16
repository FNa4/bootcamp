#include <stdio.h>
int main () {
    int a;

    printf ("Please enter an integer: ");
    scanf ("%d", &a);

    if (a % 5 == 0) {
        if (a % 4 == 0) {
            printf ("%d is divisible by both 4 and 5.\n", a);
        }
        else {
            printf ("%d is only divisible by 5.\n", a);
        }
    }
    else if (a % 4 == 0) {
        printf ("%d is only divisible by 4.\n", a);
    }
    else {
        printf ("%d is divisble by neither 4 nor 5.\n", a);
    }

    return 0;

}