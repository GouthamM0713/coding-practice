#include <stdio.h>

int main() {
    int a, b, x, y, temp;

    printf("Enter two positive numbers: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Enter positive numbers\n");
        return 0;
    }

    x = a;
    y = b;

    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }

    printf("LCM = %d\n", (a / x) * b);
    return 0;
}