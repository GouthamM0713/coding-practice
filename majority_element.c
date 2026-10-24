#include <stdio.h>

int main(void) {
    int a[100], n, i;
    int candidate = 0, votes = 0, count = 0;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    for (i = 0; i < n; i++) {
        if (votes == 0) {
            candidate = a[i];
            votes = 1;
        } else if (a[i] == candidate) {
            votes++;
        } else {
            votes--;
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i] == candidate)
            count++;
    }

    if (count > n / 2)
        printf("Majority element: %d\n", candidate);
    else
        printf("No majority element found.\n");

    return 0;
}