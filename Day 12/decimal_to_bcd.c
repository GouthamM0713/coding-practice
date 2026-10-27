#include <stdio.h>

int main(void) {
    char n[100];

    printf("Enter a non-negative integer: ");
    scanf("%99s", n);

    for (int i = 0; n[i]; i++) {
        if (n[i] < '0' || n[i] > '9') {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("BCD: ");

    for (int i = 0; n[i]; i++) {
        int d = n[i] - '0';

        for (int bit = 3; bit >= 0; bit--)
            printf("%d", (d >> bit) & 1);

        printf(" ");
    }

    printf("\n");
    return 0;
}