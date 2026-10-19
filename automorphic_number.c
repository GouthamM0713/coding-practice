#include <stdio.h>

int main() {
    long long n, square, temp, divisor = 1;

    printf("Enter a non-negative number: ");
    scanf("%lld", &n);

    if (n < 0) {
        printf("Invalid input");
        return 0;
    }

    square = n * n;
    temp = n;

    do {
        divisor *= 10;
        temp /= 10;
    } while (temp > 0);


    if (square % divisor == n)
        printf("Automorphic number\n");
    else
        printf("Not an automorphic number\n");

    printf("Square = %lld\n", square);
    return 0;
}