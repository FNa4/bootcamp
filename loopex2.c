#include <stdio.h>
int main () {
    int a = 32;
    int b;

    printf ("Please enter a number between 0 and 100: ");
    scanf ("%d", &b);

    while (b != 32) {
        if (b > 32) {
            printf ("Too high!\n");
        }
        else {
            printf ("Too low!\n");
        }
        printf ("Incorrect answer. Please try again: ");
        scanf ("%d", &b);
    }
    
    printf ("Correct answer.\n");

    return 0;
}