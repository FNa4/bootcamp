#include <stdio.h>
int main () {
    int a;

    printf("Please enter a number: \n");
    scanf("%d", &a);

    while (a != -1) {
        if (a >= 0 && a <= 100) {
            printf ("Your number is within the range of 0 and 100, but is not the termination value.\n");
        }
        else {
            printf("Your value is neither the termination value, nor is it in the range of 0 and 100.\n");
        }
        printf("Please enter a number: \n");
        scanf("%d", &a);
    }
    printf("You have entered the termination value.\n");
     

    return 0;
    }
