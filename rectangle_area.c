
#include <stdio.h>

int main(void) {
    float length, breadth, area;

    printf("Enter length and breadth: ");
    scanf("%f %f", &length, &breadth);

    area = length * breadth;

    printf("Area = %.2f\n", area);

    return 0;
}
