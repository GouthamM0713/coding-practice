#include <stdio.h>

int main(void) {
    int a[100], n, i, found = 0;
    long long total = 0, left = 0;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
        total += a[i];
    }

    for (i = 0; i < n; i++) {
        total -= a[i];

        if (left == total) {
            printf("Equilibrium index: %d\n", i);
            found = 1;
        }

        left += a[i];
    }

    if (!found)
        printf("No equilibrium index found.\n");

    return 0;
}