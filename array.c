#include <stdio.h>
int main () {
    int my_array[5] = {4, 12, 32, 5, 84};
    int i=2;

    printf ("The first element of the array is %d\n", my_array[0]);

    for (i=1; i <= 4; i++) {
        printf ("The next element of the array is %d\n", my_array[i]);
    }

    return 0;
}