#include <stdio.h>

int main(void) {
    int a[100], n, k, i, j, maximum;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    printf("Enter window size: ");
    if (scanf("%d", &k) != 1 || k < 1 || k > n)
        return 1;

    printf("Window maximums: ");

    for (i = 0; i <= n - k; i++) {
        maximum = a[i];

        for (j = i + 1; j < i + k; j++) {
            if (a[j] > maximum)
                maximum = a[j];
        }

        printf("%d ", maximum);
    }

    printf("\n");
    return 0;
}