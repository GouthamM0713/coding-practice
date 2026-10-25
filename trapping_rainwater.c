#include <stdio.h>

int main(void) {
    int h[100], n;
    int left[100], right[100];

    printf("Enter number of bars: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) return 1;

    printf("Enter bar heights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        if (h[i] < 0) return 1;
    }

    left[0] = h[0];
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] > h[i] ? left[i - 1] : h[i];

    right[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] > h[i] ? right[i + 1] : h[i];

    long long water = 0;

    for (int i = 0; i < n; i++) {
        int level = left[i] < right[i] ? left[i] : right[i];
        water += level - h[i];
    }

    printf("Trapped water: %lld\n", water);
    return 0;
}