#include <stdio.h>

int main(void) {
    int n, found = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 0) {
        for (int i = 0; i <= n / (i + 1) && i * (i + 1) <= n; i++) {
            if (i * (i + 1) == n) {
                found = 1;
                break;
            }
        }
    }

    if (found)
        printf("%d is a Pronic Number.\n", n);
    else
        printf("%d is not a Pronic Number.\n", n);

    return 0;
}
