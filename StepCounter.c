#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

void tokeniseRecord(char *record, char *date, char *time, char *steps) {
    char *token = strtok(record, ",");
    strcpy(date, token);

    token = strtok(NULL, ",");
    strcpy(time, token);

    token = strtok(NULL, ",");
    strcpy(steps, token);
}

void sortByStepCount(FITNESS_DATA *data, int numRecords) {
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = i + 1; j < numRecords; j++) {
            if (data[i].steps < data[j].steps) {
                FITNESS_DATA temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int getTotalRecords(FILE *file) {
    int numRecords = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        numRecords++;
    }

    rewind(file);
    return numRecords;
}

void findFewestSteps(FITNESS_DATA *data, int numRecords) {
    int minSteps = data[0].steps;
    int minIndex = 0;

    for (int i = 1; i < numRecords; i++) {
        if (data[i].steps < minSteps) {
            minSteps = data[i].steps;
            minIndex = i;
        }
    }

    printf("Fewest steps: %s %s\n\n", data[minIndex].date, data[minIndex].time);
}

void findLargestSteps(FITNESS_DATA *data, int numRecords) {
    int maxSteps = data[0].steps;
    int maxIndex = 0;

    for (int i = 1; i < numRecords; i++) {
        if (data[i].steps > maxSteps) {
            maxSteps = data[i].steps;
            maxIndex = i;
        }
    }

    printf("Largest steps: %s %s\n\n", data[maxIndex].date, data[maxIndex].time);
}


double findMeanSteps(FITNESS_DATA *data, int numRecords) {
    int totalSteps = 0;

    for (int i = 0; i < numRecords; i++) {
        totalSteps += data[i].steps;
    }

    return (double)totalSteps / numRecords;
}

void findLongestAbove500(FITNESS_DATA *data, int numRecords) {
int currentStart = -1; 
    int currentEnd = -1;
    int longestStart = -1; 
    int longestEnd = -1; 
    int currentLength = 0;
    int longestLength = 0; 

    for (int i = 0; i < numRecords; i++) {
        if (data[i].steps > 500) {
            if (currentStart == -1) {
                currentStart = i;
            }
            currentEnd = i;
            currentLength = currentEnd - currentStart + 1;

            if (currentLength > longestLength) {
                longestStart = currentStart;
                longestEnd = currentEnd;
                longestLength = currentLength;
            }
        } else {
            currentStart = -1;
            currentEnd = -1;
            currentLength = 0;
        }
    }

    if (longestStart != -1) {
        printf("Longest period start: %s %s\n", data[longestStart].date, data[longestStart].time);
        printf("Longest period end: %s %s\n\n", data[longestEnd].date, data[longestEnd].time);
    } else {
        printf("No period above 500 steps found.\n\n");
    }
}

int main() {
    char filename[100];
    FILE *file = NULL;
    FITNESS_DATA *fitnessArray = NULL;
    int numRecords = 0;
    char buffer[100];

    while (1) {
        printf("Menu:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        char choice;
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter filename: ");
                scanf("%s", filename);

                file = fopen(filename, "r");
                if (file == NULL) {
                    fprintf(stderr, "Error: could not open file\n\n");
                    return 1;
                }

                numRecords = getTotalRecords(file);
                fitnessArray = (FITNESS_DATA *)malloc(numRecords * sizeof(FITNESS_DATA));
                if (fitnessArray == NULL) {
                    fprintf(stderr, "Error: memory allocation failed\n\n");
                    fclose(file);
                    return 1;
                }

                for (int i = 0; i < numRecords; i++) {
                    if (fgets(buffer, sizeof(buffer), file) != NULL) {
                        char date[11], time[6], steps[10];
                        tokeniseRecord(buffer, date, time, steps);

                        strcpy(fitnessArray[i].date, date);
                        strcpy(fitnessArray[i].time, time);
                        fitnessArray[i].steps = atoi(steps);
                    }
                }

                fclose(file);
                break;

            case 'B':
                if (file == NULL || fitnessArray == NULL) {
                    fprintf(stderr, "Error: no file or data specified\n\n");
                    return 1; 
                }
                printf("Total records: %d\n", numRecords);
                break;

            case 'C':
                if (file == NULL || fitnessArray == NULL) {
                    fprintf(stderr, "Error: no file or data specified\n\n");
                    return 1;
                }
                findFewestSteps(fitnessArray, numRecords);
                break;

            case 'D':
                if (file == NULL || fitnessArray == NULL) {
                    fprintf(stderr, "Error: no file or data specified\n\n");
                    return 1;
                }
                findLargestSteps(fitnessArray, numRecords);
                break;

            case 'E':
                if (file == NULL || fitnessArray == NULL) {
                    fprintf(stderr, "Error: no file or data specified\n\n");
                    return 1;
                }
                printf("Mean step count: %.0f\n", findMeanSteps(fitnessArray, numRecords));
                break;

            case 'F':
                if (file == NULL || fitnessArray == NULL) {
                    fprintf(stderr, "Error: no file or data specified\n\n");
                    return 1;
                }
                findLongestAbove500(fitnessArray, numRecords);
                break;

            case 'Q':
                if (fitnessArray != NULL) {
                    free(fitnessArray);
                    fitnessArray = NULL;
                }
                printf("Program ended.\n");
                return 0;


            default:
                printf("Invalid choice. Please enter a valid option.\n\n");
        }
    }
}