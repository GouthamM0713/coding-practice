#include <stdio.h>

long long merge(int a[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    long long count = 0;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            count += m - i + 1;
        }
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = temp[i];

    return count;
}

long long sortCount(int a[], int temp[], int l, int r) {
    if (l >= r) return 0;

    int m = l + (r - l) / 2;

    return sortCount(a, temp, l, m)
         + sortCount(a, temp, m + 1, r)
         + merge(a, temp, l, m, r);
}

int main(void) {
    int a[1000], temp[1000], n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) return 1;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Inversion count: %lld\n",
           sortCount(a, temp, 0, n - 1));

    return 0;
}