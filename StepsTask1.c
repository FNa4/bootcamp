#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here

#define MAX_RECORDS 1000

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() {
    FILE *file = fopen("FitnessData_2023.csv", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    FITNESS_DATA fitnessDataArray[MAX_RECORDS];
    int numRecords = 0;

    // Read the file and store data in the array
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL && numRecords < MAX_RECORDS) {
        char date[11], time[6], steps[10];
        tokeniseRecord(buffer, ",", date, time, steps);
        strcpy(fitnessDataArray[numRecords].date, date);
        strcpy(fitnessDataArray[numRecords].time, time);
        fitnessDataArray[numRecords].steps = atoi(steps);
        numRecords++;
    }

    fclose(file);

    // Print the number of records
    printf("Number of records in file: %d\n", numRecords);

    // Print the first three rows
    printf("First three rows of the file:\n");
    for (int i = 0; i < 3 && i < numRecords; i++) {
        printf("%s/%s/%d\n", fitnessDataArray[i].date, fitnessDataArray[i].time, fitnessDataArray[i].steps);
    }

    return 0;
}