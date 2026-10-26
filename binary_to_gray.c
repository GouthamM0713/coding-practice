
#include <stdio.h>

int main(void) {
    unsigned int binary, gray;

    printf("Enter a non-negative binary integer: ");
    scanf("%u", &binary);

    gray = binary ^ (binary >> 1);

    printf("Gray code (decimal representation) = %u\n",
           gray);

    printf("Gray code (binary) = ");

    int started = 0;

    for (int i = 31; i >= 0; i--) {
        int bit = (gray >> i) & 1;

        if (bit)
            started = 1;

        if (started)
            printf("%d", bit);
    }

    if (!started)
        printf("0");

    printf("\n");
    return 0;
}