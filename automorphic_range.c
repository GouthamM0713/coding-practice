
#include <stdio.h>

int isAutomorphic(int n) {
    long long square = (long long)n * n;
    int temp = n;

    while (temp > 0) {
        if (temp % 10 != square % 10)
            return 0;

        temp /= 10;
        square /= 10;
    }

    return 1;
}

int main(void) {
    int start, end, found = 0;

    printf("Enter range: ");
    scanf("%d%d", &start, &end);

    if (start < 0 || end < start) {
        printf("Invalid range\n");
        return 0;
    }

    printf("Automorphic numbers: ");

    for (int i = start; i <= end; i++) {
        if (isAutomorphic(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
    return 0;
}