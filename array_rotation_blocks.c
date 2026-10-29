#include <stdio.h>

void swapBlock(int a[], int first, int second, int len) {
    int i, temp;

    for (i = 0; i < len; i++) {
        temp = a[first + i];
        a[first + i] = a[second + i];
        a[second + i] = temp;
    }
}

void rotateLeft(int a[], int n, int d) {
    int i, j;

    if (n <= 1)
        return;

    d %= n;

    if (d < 0)
        d += n;

    if (d == 0)
        return;

    i = d;
    j = n - d;

    while (i != j) {
        if (i < j) {
            swapBlock(a, d - i, d + j - i, i);
            j -= i;
        } else {
            swapBlock(a, d - i, d, j);
            i -= j;
        }
    }

    swapBlock(a, d - i, d, i);
}

int main(void) {
    int a[100], n, d, i;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    printf("Enter left rotation count: ");
    if (scanf("%d", &d) != 1)
        return 1;

    rotateLeft(a, n, d);

    printf("Rotated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}