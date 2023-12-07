#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for tokeniseRecord
void tokeniseRecord(char *record, char *date, char *time, char *steps);

// Define the structure for fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function prototype for sorting the data by step count in descending order
void sortByStepCount(FITNESS_DATA *data, int numRecords);

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the input file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: invalid file\n");
        return 1;  // Exit with an error code
    }

    // Read the data from the file
    int numRecords = 0;
    char buffer[100];  // Assuming a maximum record length of 100 characters

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        numRecords++;
    }

    // Allocate memory for the array of fitness data
    FITNESS_DATA *fitnessArray = (FITNESS_DATA *)malloc(numRecords * sizeof(FITNESS_DATA));

    // Rewind the file to the beginning
    rewind(file);

    // Read the data into the fitness array
    for (int i = 0; i < numRecords; i++) {
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            char date[11], time[6], steps[10];
            tokeniseRecord(buffer, date, time, steps);

            strcpy(fitnessArray[i].date, date);
            strcpy(fitnessArray[i].time, time);
            fitnessArray[i].steps = atoi(steps);
        }
    }

    // Close the input file
    fclose(file);

    // Sort the data by step count in descending order
    sortByStepCount(fitnessArray, numRecords);

    // Add ".tsv" extension to the filename
    strcat(filename, ".tsv");

    // Open the output file
    FILE *outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error creating output file\n");
        return 1;  // Exit with an error code
    }

    // Write the sorted data to the output file in TSV format
    for (int i = 0; i < numRecords; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", fitnessArray[i].date, fitnessArray[i].time, fitnessArray[i].steps);
    }

    // Close the output file
    fclose(outputFile);

    // Free allocated memory
    free(fitnessArray);

    return 0;
}

// Function to tokenise a record into date, time, and steps
void tokeniseRecord(char *record, char *date, char *time, char *steps) {
    char *token = strtok(record, ",");
    strcpy(date, token);

    token = strtok(NULL, ",");
    strcpy(time, token);

    token = strtok(NULL, ",");
    strcpy(steps, token);
}

// Function to sort the data by step count in descending order
void sortByStepCount(FITNESS_DATA *data, int numRecords) {
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = i + 1; j < numRecords; j++) {
            if (data[i].steps < data[j].steps) {
                // Swap the records if they are out of order
                FITNESS_DATA temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}