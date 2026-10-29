#include <stdio.h>

int main(void) {
    int a[100], n, missing;
    long long expected = 0, actual = 0;

    printf("Enter N (maximum 100): ");
    scanf("%d", &n);

    if (n < 2 || n > 100) {
        printf("N must be between 2 and 100.\n");
        return 0;
    }

    printf("Enter %d distinct numbers from 1 to %d:\n",
           n - 1, n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);

        if (a[i] < 1 || a[i] > n) {
            printf("Invalid number.\n");
            return 0;
        }

        actual += a[i];
    }

    expected = (long long)n * (n + 1) / 2;
    missing = (int)(expected - actual);

    printf("Missing number = %d\n", missing);

    return 0;
}
