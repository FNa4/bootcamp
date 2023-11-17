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

    fp = fopen("/workspaces/bootcamp/FitnessData_2023.csv", "r");
    if (fp = NULL) {
        printf("Error");
        return 1;
    }

    FITNESS_DATA records[100];
    int read = 0;
    int entries = 0;
    do {
        read = fscanf(fp,"%c[11], %c[6], %d\n", records[entries].date, records[entries].time, &records[entries].steps);
    } while (!feof(fp));

    fclose (fp);

    printf("Number of records in file: %d\n", entries);

    for (int i=0; i<3; i++) {
        printf("%c %c %d\n", records[i].date, records[i].time, records[i].steps);
    }

}