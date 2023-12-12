#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

int getTotalRecords(FILE *file);
void findFewestSteps(FITNESS_DATA *data, int numRecords);
void findLargestSteps(FITNESS_DATA *data, int numRecords);
double findMeanSteps(FITNESS_DATA *data, int numRecords);
void findLongestAbove500(FITNESS_DATA *data, int numRecords);

#endif