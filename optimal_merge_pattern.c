#include <stdio.h>

int main(void) {
    int n, a[100];
    long long total = 0;

    scanf("%d", &n);
    if (n < 2 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) return 0;
    }

    int size = n;

    while (size > 1) {
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (a[j] < a[i]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }

        int sum = a[0] + a[1];
        total += sum;

        printf("Merge %d and %d = %d\n", a[0], a[1], sum);

        a[0] = sum;

        for (int i = 1; i < size - 1; i++)
            a[i] = a[i + 1];

        size--;
    }

    printf("Minimum merge cost = %lld\n", total);
    return 0;
}