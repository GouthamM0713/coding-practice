#include <stdio.h>

int main() {
    long long n, square, temp;

    printf("Enter a number: ");
    scanf("%lld", &n);

    if (n < 0) {
        printf("Not an automorphic number\n");
        return 0;
    }

    square = n * n;
    temp = n;

    while (temp > 0) {
        if (temp % 10 != square % 10) {
            printf("Not an automorphic number\n");
            return 0;
        }

        temp /= 10;
        square /= 10;
    }

    printf("Automorphic number\n");
    return 0;
}