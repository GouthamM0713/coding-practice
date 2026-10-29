#include <stdio.h>

int main(void) {
    int n;
    long long value;

    printf("Enter number of rows (1-30): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 30) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int space = 0; space < n - i; space++)
            printf(" ");

        value = 1;

        for (int j = 0; j <= i; j++) {
            printf("%lld ", value);
            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}