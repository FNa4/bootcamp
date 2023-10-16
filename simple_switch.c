#include <stdio.h>
int main () {
    int a;

    printf("Select an option:");
    scanf("%d", &a);

    switch (a) {
        case 0: printf("Option 0 has been selected.\n");
        break;

        case 1: printf("Option 1 has been selected.\n");
        break;

        default: printf("A different option has been selected.\n");
        break;
    }
}