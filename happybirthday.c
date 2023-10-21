#include <stdio.h>
void birthday (char name[], int age) {
    printf("Happy birthday dear %s!\n", name);
    printf("You are %d years old.", age);
}

int main () {
    char name[15];
    int age;

    printf("What is your name?");
    scanf("%s", name);

    printf("How old are you?");
    scanf("%d", &age);

    birthday (name, age);

    return 0;

}