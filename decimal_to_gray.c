#include <stdio.h>

int main(void) {
    unsigned int n;
    printf("Enter a decimal number: ");
    scanf("%u", &n);

    printf("Gray code: %u\n", n ^ (n >> 1));
    return 0;
}