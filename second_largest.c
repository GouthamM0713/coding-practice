#include <stdio.h>

int main() {
    int a[100], n, i, j, temp, found = 0;

    printf("Enter number of elements (2-100): ");
    scanf("%d", &n);

    if (n < 2 || n > 100)
        return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (i = 1; i < n; i++) {
        if (a[i] != a[0]) {
            printf("Second largest = %d", a[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No second-largest distinct value");

    return 0;
}