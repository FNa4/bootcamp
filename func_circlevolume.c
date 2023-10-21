#include <stdio.h>
float volume (float radius){
    float volume = radius * radius * radius * 1.333333;

    return (volume);
}

int main () {
    float radius;
    printf ("Enter circle radius:");
    scanf("%f", &radius);

    printf("The volume if the circle is %.3f\n", volume(radius));

    return 0;
}