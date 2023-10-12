#include <stdio.h>
int main() {
    int a = 1;

    while ( a < 100) {
        printf ("a is equal to %d\n", a);
        a *= 2;
    }
    printf ("The loop is finished. a is equal to %d\n", a);

    return 0;
}