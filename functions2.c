#include <stdio.h>
float sum (float a, float b) {
    float answer;

    answer = a + b;

    return answer;
}

int main () {
    int y = 2;

    float z = sum(5.87, y); // calling new function

    printf("The sum of 5.87 and %d is %.2f\n.", y, z);

}