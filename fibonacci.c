#include <stdio.h>

int main(void) {
    int n;
    unsigned long long a = 0, b = 1, next;

    printf("Enter number of terms (1 to 92): ");
    scanf("%d", &n);

    if (n < 1 || n > 92) {
        printf("Enter a number between 1 and 92\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("%llu ", a);

        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");

    return 0;
}
