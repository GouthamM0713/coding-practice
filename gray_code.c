#include <stdio.h>

int main(void) {
    unsigned int n, gray;

    printf("Enter a non-negative integer: ");
    if (scanf("%u", &n) != 1)
        return 1;

    gray = n ^ (n >> 1);

    printf("Binary number = %u\n", n);
    printf("Gray code value = %u\n", gray);

    printf("Gray code in binary: ");
    {
        int i, started = 0;

        for (i = (int)(sizeof(n) * 8) - 1; i >= 0; i--) {
            unsigned int bit = (gray >> i) & 1u;

            if (bit)
                started = 1;

            if (started)
                printf("%u", bit);
        }

        if (!started)
            printf("0");
    }

    printf("\n");
    return 0;
}