#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter diamond size (1-9): ");
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("Enter a size between 1 and 9");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%d", j);

        for (j = i - 1; j >= 1; j--)
            printf("%d", j);

        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = i; j < n; j++)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%d", j);

        for (j = i - 1; j >= 1; j--)
            printf("%d", j);

        printf("\n");
    }

    return 0;
}