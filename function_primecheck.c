#include <stdio.h>
int primecheck (int number) {
    int counter = number;
    int value;
    if (number < 0) {
        printf ("Invalid number.");
    }
    else {
        for (counter = 1; counter <= 100; counter++) {
            if (number%counter == 0) {
                value = 1;
                return value;
            }
            else {
                value = 0;
                return value;
            }
        }
    }
    return number;
    }


int main () {
    int number;
    int value;

    printf("Please enter an integer between 0 and 100: ");
    scanf("%d", &number);

    primecheck(number);

    printf ("%d", value);

    return 0;
}