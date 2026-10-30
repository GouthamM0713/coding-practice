#include <stdio.h>

int main() {
    int n, a[100];

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i], j;

            for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
                a[j] = a[j-gap];

            a[j] = temp;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}