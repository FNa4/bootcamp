#include <stdio.h>
int main () {
    int mark;

    printf ("Please enter mark: ");
    scanf("%d", &mark);

    if (mark >= 0 && mark <= 100) {
    if (mark == 0) {
        printf ("Your mark is %d. You are an idiot.\n", mark);
    }
    else if (mark >= 40) {
        printf("The mark of %d is a pass\n", mark);
    }
    else {
        printf("The mark of %d is a fail\n", mark);
    }
    }
    else {
        printf("The mark must be between 0 and 100.\n");
    }
    return 0;
}