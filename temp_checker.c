#include <stdio.h>
int main () {
    int temp;

    printf ("Please enter the temperature: \n");
    scanf ("%d", &temp);

    if (temp >= -10 && temp <= 40) {
        printf ("%d is a valid temperature between -10 and 40.\n", temp);
    }
    else {
        printf ("%d is invalid as it is not between -10 and 40.\n", temp);
    }

    return 0;
}