#include <stdio.h>

int main(void) {
    int a[10], n, i, j;
    unsigned int mask, total;

    printf("Enter number of elements (0-10): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 10)
        return 1;

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    total = 1u << n;

    printf("All subsets:\n");

    for (mask = 0; mask < total; mask++) {
        printf("{ ");

        for (j = 0; j < n; j++) {
            if (mask & (1u << j))
                printf("%d ", a[j]);
        }

        printf("}\n");
    }

    return 0;
}