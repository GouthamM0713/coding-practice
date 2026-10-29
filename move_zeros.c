#include <stdio.h>

int main(void) {
    int a[100], n, j = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            a[j++] = a[i];
    }

    while (j < n)
        a[j++] = 0;

    printf("Result: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
