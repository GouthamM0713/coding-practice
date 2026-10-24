#include <stdio.h>

int main(void) {
    long long n, square, temp;
    long long divisor = 1, left, right;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1 ||
        n < 0 || n > 3037000499LL) {
        printf("Invalid input.\n");
        return 1;
    }

    square = n * n;
    temp = n;

    do {
        divisor *= 10;
        temp /= 10;
    } while (temp > 0);

    left = square / divisor;
    right = square % divisor;

    if (left + right == n)
        printf("%lld is a Kaprekar number.\n", n);
    else
        printf("%lld is not a Kaprekar number.\n", n);

    return 0;
}