#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input");
        return 0;
    }

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }

    printf("Sum of proper divisors = %d\n", sum);

    if (sum > n)
        printf("Abundant number\n");
    else
        printf("Not an abundant number\n");

    return 0;
}