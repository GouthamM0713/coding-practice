#include <stdio.h>

int main(void) {
    int n, a[100];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) return 1;

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long maxEnd = a[0], minEnd = a[0];
    long long best = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            long long t = maxEnd;
            maxEnd = minEnd;
            minEnd = t;
        }

        maxEnd = a[i] > maxEnd * a[i] ? a[i] : maxEnd * a[i];
        minEnd = a[i] < minEnd * a[i] ? a[i] : minEnd * a[i];

        if (maxEnd > best) best = maxEnd;
    }

    printf("Maximum product: %lld\n", best);
    return 0;
}