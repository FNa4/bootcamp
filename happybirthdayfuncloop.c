#include <stdio.h>
void birthday (char name[], int age) {
    printf("Happy birthday dear %s!\n", name);
    printf("You are %d years old.", age);
}

int main () {
    char name[15];
    int age;
    char option;

    printf("What is your name?");
    scanf("%s", name);

    printf("How old are you?");
    scanf("%d", &age);

    printf("Is it your birthday today? Enter 'Y' or 'N':\n");
    scanf("%c", &option);
    switch (option) {
        case 'Y': birthday (name, age);
            break;

        case 'N': break;

        default: break;
    }

    

    return 0;

}