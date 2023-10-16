#include <stdio.h>
int main () {
    int radius;
    int diameter;
    float circumference;
    const float PI = 3.1415926;
    float area;

    printf("Please enter the radius of the circle: ");
    scanf("%d", &radius);

    diameter = radius * 2;
    circumference = diameter * PI;
    area = PI * radius * radius;

    printf("The diameter of the circle is %.2f\nThe area of the circle is %.2f\n", circumference, area);


    return 0;

}