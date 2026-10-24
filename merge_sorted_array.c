#include <stdio.h>

int main(void) {
    int a[] = {1, 4, 7};
    int b[] = {2, 5, 8};
    int c[6], i = 0, j = 0, k = 0;

    while (i < 3 && j < 3) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < 3) c[k++] = a[i++];
    while (j < 3) c[k++] = b[j++];

    for (i = 0; i < 6; i++)
        printf("%d ", c[i]);

    return 0;
}
