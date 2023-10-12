#include <stdio.h>
int main () {
    float radius, area;

    printf ("Please enter the radius of the circle: ");
    scanf ("%f", &radius);

    area = radius * 3.14159;

    printf ("the area of the cirecle is %.3f\n", area);

    return 0;
}