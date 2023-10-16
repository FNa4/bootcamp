#include <stdio.h>
int main () {
    int mark;

    printf ("Please enter your mark between 0 and 100.\n");
    scanf ("%d", &mark);

    switch (mark/10) {
        case 0: printf ("Your mark is %d. You are an idiot.\n", mark);
        break;

        case 1:
        case 2:
        case 3:
        case 4: printf ("Your mark is %d. You have failed.\n", mark);
        break;

        case 5:
        case 6: printf ("Your mark is %d. You have passed.\n", mark);
        break;

        default: printf ("Your mark is %d. You have passed with distinction.\n", mark);
        break;
    }
}