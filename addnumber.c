#include <stdio.h>
int main () {
    int num1, num2, total;

    printf ("Please enter first number: ");
    scanf ("%d", &num1);
    printf ("Please enter second number: ");
    scanf ("%d",&num2);

    total = num1 + num2;

    printf ("The total of your two numbers is %d\n", total);

    return 0;
}