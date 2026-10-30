#include <stdio.h>

void flip(int a[], int k) {
    int i = 0, j = k;

    while (i < j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

int main() {
    int n, a[100];

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int size = n; size > 1; size--) {
        int max = 0;

        for (int i = 1; i < size; i++)
            if (a[i] > a[max]) max = i;

        if (max != size - 1) {
            flip(a, max);
            flip(a, size - 1);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
