#include <stdio.h>

int main() {
    int n, sum;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Enter a non-negative number");
        return 0;
    }

    while (n >= 10) {
        sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        n = sum;
    }

    printf("Digital root = %d\n", n);
    return 0;
}