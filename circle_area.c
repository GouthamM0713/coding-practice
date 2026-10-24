
#include <stdio.h>

int main(void) {
    float radius, area;

    printf("Enter radius: ");
    scanf("%f", &radius);

    area = 3.14159f * radius * radius;

    printf("Area of circle = %.2f\n", area);

    return 0;
}
