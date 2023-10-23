#include <stdlib.h>

FILE *open_file = (char filename[], mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror ("");
        exit(1);
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}