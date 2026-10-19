#include <stdio.h>

int main() {
    int rows, i, j;
    long long value;

    printf("Enter number of rows (1-20): ");
    scanf("%d", &rows);

    if (rows < 1 || rows > 20) {
        printf("Enter rows between 1 and 20");
        return 0;
    }

    for (i = 0; i < rows; i++) {
        value = 1;

        for (j = 0; j <= i; j++) {
            printf("%lld ", value);
            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}