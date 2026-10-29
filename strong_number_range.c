
#include <stdio.h>

int factorial(int n) {
    int f = 1;

    for (int i = 2; i <= n; i++)
        f *= i;

    return f;
}

int isStrong(int n) {
    int original = n, sum = 0;

    do {
        sum += factorial(n % 10);
        n /= 10;
    } while (n > 0);

    return sum == original;
}

int main(void) {
    int start, end, found = 0;

    printf("Enter range: ");
    scanf("%d%d", &start, &end);

    if (start < 0 || end < start) {
        printf("Invalid range\n");
        return 0;
    }

    printf("Strong numbers: ");

    for (int i = start; i <= end; i++) {
        if (isStrong(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
    return 0;
}