#include <stdio.h>

int main(void) {
    int a[] = {45, 12, 89, 23, 7};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
