#include <stdio.h> 
int main () {
    int a;

    printf ("Welcome to the menu page.\nPlease select an option from the list below:\n1 - For Loops\n2 - While Loops\n3 - If-else Statements\n4 - Switch Statements\n5 - Help\nType your option number:");
    scanf ("%d", &a);

    switch (a) {
        case 1: printf("You have selected Option 1 - For Loops.\n");
        break;

        case 2: printf("You have selected Option 2 - While Loops.\n");
        break;

        case 3: printf("You have selected Option 3 - If-Else Statements.\n");
        break;

        case 4: printf("You have selected Option 4 - Switch Statements.\n");
        break;

        case 5: printf("You have selected Option 5 - Help.\n");
        break;

        default: printf("Invalid option. Please select a option from the menu.\n");
        break;
    }

    return 0;
}