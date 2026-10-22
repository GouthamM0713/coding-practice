#include <stdio.h>

int main(void) {
    int n = 254;
    char hex[32];
    char digits[] = "0123456789ABCDEF";
    int i = 0;

    if (n == 0) {
        printf("Hexadecimal: 0\n");
        return 0;
    }

    while (n > 0) {
        hex[i++] = digits[n % 16];
        n /= 16;
    }

    printf("Hexadecimal: ");

    while (i > 0)
        printf("%c", hex[--i]);

    printf("\n");
    return 0;
}
