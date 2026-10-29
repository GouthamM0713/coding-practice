#include <stdio.h>

#define MAX 20

int main(void) {
    int a[MAX], b[MAX], c[MAX], n;

    printf("Enter maximum degree (0-19): ");
    if (scanf("%d", &n) != 1 || n < 0 || n >= MAX) {
        printf("Invalid degree\n");
        return 1;
    }

    printf("Enter coefficients of first polynomial\n");
    printf("From degree 0 to %d:\n", n);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);

    printf("Enter coefficients of second polynomial\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i <= n; i++)
        c[i] = a[i] + b[i];

    printf("Sum = ");

    for (int i = n; i >= 0; i--) {
        if (c[i] != 0) {
            printf("%d", c[i]);

            if (i > 0)
                printf("x^%d", i);

            if (i > 0) {
                int remaining = 0;
                for (int j = i - 1; j >= 0; j++)
                    if (c[j] != 0)
                        remaining = 1;

                if (remaining)
                    printf(" + ");
            }
        }
    }

    printf("\n");
    return 0;
}