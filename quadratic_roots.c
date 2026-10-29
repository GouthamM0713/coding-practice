
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, d;

    printf("Enter a, b and c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0)
            printf("Not a linear equation\n");
        else
            printf("Root = %.2f\n", -c / b);
        return 0;
    }

    d = b * b - 4 * a * c;

    if (d > 0) {
        printf("Root 1 = %.2f\n",
               (-b + sqrt(d)) / (2 * a));
        printf("Root 2 = %.2f\n",
               (-b - sqrt(d)) / (2 * a));
    } else if (d == 0) {
        printf("Equal roots = %.2f\n", -b / (2 * a));
    } else {
        printf("Root 1 = %.2f + %.2fi\n",
               -b / (2 * a), sqrt(-d) / fabs(2 * a));
        printf("Root 2 = %.2f - %.2fi\n",
               -b / (2 * a), sqrt(-d) / fabs(2 * a));
    }

    return 0;
}