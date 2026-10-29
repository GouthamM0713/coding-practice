
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {
    int numerator, denominator, g;

    printf("Enter numerator and denominator: ");
    scanf("%d%d", &numerator, &denominator);

    if (denominator == 0) {
        printf("Denominator cannot be zero\n");
        return 0;
    }

    g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    printf("Simplified fraction = %d/%d\n",
           numerator, denominator);
    return 0;
}