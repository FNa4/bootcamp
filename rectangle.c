#include <stdio.h>
int main () {
    float width, height, area;

    printf("Enter width:");
    scanf("%f", &width);
    printf("Enter height:");
    scanf("%f", &height);

    area = width * height;

    printf("The area of the rectangle is %.4f\n", area);

    return 0;

}