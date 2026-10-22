#include <stdio.h>

int main(void) {
    int n;
    unsigned long long fact = 1;

    printf("Enter a number (0 to 20): ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Enter a number between 0 and 20\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    printf("Factorial = %llu\n", fact);

    return 0;
}
