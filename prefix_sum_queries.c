#include <stdio.h>

int main(void) {
    int a[101], n, q, i, left, right;
    long long prefix[101];

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    prefix[0] = 0;

    printf("Enter array elements: ");
    for (i = 1; i <= n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;

        prefix[i] = prefix[i - 1] + a[i];
    }

    printf("Enter number of queries: ");
    if (scanf("%d", &q) != 1 || q < 0)
        return 1;

    while (q--) {
        printf("Enter left and right positions (1-based): ");

        if (scanf("%d %d", &left, &right) != 2 ||
            left < 1 || right > n || left > right) {
            printf("Invalid range.\n");
            return 1;
        }

        printf("Range sum = %lld\n",
               prefix[right] - prefix[left - 1]);
    }

    return 0;
}