#include <stdio.h>

int main() {
    int n, octal[32], i = 0, j;

    printf("Enter a non-negative decimal number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input");
        return 0;
    }

    if (n == 0) {
        printf("Octal = 0");
        return 0;
    }

    while (n > 0) {
        octal[i++] = n % 8;
        n /= 8;
    }

    printf("Octal = ");

    for (j = i - 1; j >= 0; j--)
        printf("%d", octal[j]);

    return 0;
}