#include <stdio.h>

int main(void) {
    int a[100], n;
    int current, maximum;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    current = maximum = a[0];

    for (int i = 1; i < n; i++) {
        if (current + a[i] < a[i])
            current = a[i];
        else
            current += a[i];

        if (current > maximum)
            maximum = current;
    }

    printf("Maximum subarray sum = %d\n", maximum);

    return 0;
}
