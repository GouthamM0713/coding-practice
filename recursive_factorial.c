#include <stdio.h>

long long factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a number (0-20): ");
    scanf("%d", &n);

    if (n < 0 || n > 20)
        printf("Invalid input");
    else
        printf("Factorial = %lld", factorial(n));

    return 0;
}