#include <stdio.h>
double area (float radius) {
float area = radius * radius * 3.1415926;

return (area);
}


int main () {
    float radius;
    printf ("Enter circle radius: ");
    scanf("%f", &radius);

    printf ("The area of the square is %.2f\n", area(radius));

    return 0;
}