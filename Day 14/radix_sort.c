#include <stdio.h>

int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

void radixSort(int a[], int n) {
    int output[100];

    for (int exp = 1, max = getMax(a, n);
         max / exp > 0; exp *= 10) {

        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int d = (a[i] / exp) % 10;
            output[--count[d]] = a[i];
        }

        for (int i = 0; i < n; i++)
            a[i] = output[i];
    }
}

int main() {
    int n, a[100];
    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) return 0;
    }

    radixSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}