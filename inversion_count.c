#include <stdio.h>

long long merge(int a[], int temp[], int left,
                int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return count;
}

long long sortCount(int a[], int temp[],
                    int left, int right) {
    int mid;
    long long count = 0;

    if (left >= right)
        return 0;

    mid = left + (right - left) / 2;

    count += sortCount(a, temp, left, mid);
    count += sortCount(a, temp, mid + 1, right);
    count += merge(a, temp, left, mid, right);

    return count;
}

int main(void) {
    int a[100], temp[100], n, i;
    long long count;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    count = sortCount(a, temp, 0, n - 1);

    printf("Inversion count = %lld\n", count);
    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}