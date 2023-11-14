#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);

    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    free(inputCopy);
}

int main () {

    FILE *fp;

    fp = fopen("FitnessData_2023.csv", "r");
    if (fp = NULL) {
        printf("Error");
        return 1;
    }
    FITNESS_DATA lines [1000];
     int read = 0;
     int records = 0;
    do {
        read = fscanf(fp,"%c[],%c[],%d", lines[records].date, lines[records].time, &lines[records].steps);
    
        if (read == 4) {
            records++;
        }

        else {
            printf("Error\n");
            return 1;
        }
    } while (!feof(fp));
    

    fclose (fp);

    printf("Number of records in file: %d\n", records);

    for (int i = 0; i < 3; i++) {
        printf("%c %c %d\n", lines[i].date, lines[i].time, lines[i].steps);
    }

}

