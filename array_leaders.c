#include <stdio.h>

int main(void) {
    int a[100], n, max;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[n - 1];

    printf("Leaders: %d ", max);

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > max) {
            max = a[i];
            printf("%d ", max);
        }
    }

    printf("\n");

    return 0;
}
