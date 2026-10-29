#include <stdio.h>

int main() {
    int n, square, sum = 0;

    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input");
        return 0;
    }

    square = n * n;

    while (square > 0) {
        sum += square % 10;
        square /= 10;
    }

    if (sum == n)
        printf("Neon number\n");
    else
        printf("Not a Neon number\n");

    return 0;
}