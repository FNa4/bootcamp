#include <stdio.h>
int main () {
    char filename[] = "data.txt";
    FILE *file = fopen(filename,"w");
    if (filename == NULL) {
        perror(" ");
        return 1;
    }
    fclose (file);
    return 0;
}