#include <stdio.h>

int main(void) {
    int a[100], n, i;
    long long result[100], prefix = 1, suffix = 1;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    for (i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= a[i];
    }

    for (i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= a[i];
    }

    printf("Products except self: ");
    for (i = 0; i < n; i++)
        printf("%lld ", result[i]);

    printf("\n");
    return 0;
}