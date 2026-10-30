#include <stdio.h>

int main() {
    int n, a[100], gap, swapped = 1;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    gap = n;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = 0;

        for (int i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                int t = a[i];
                a[i] = a[i + gap];
                a[i + gap] = t;
                swapped = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}