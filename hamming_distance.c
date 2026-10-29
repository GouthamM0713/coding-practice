#include <stdio.h>

int main(void) {
    unsigned int a, b, x;
    int distance = 0;

    printf("Enter two non-negative integers: ");
    if (scanf("%u %u", &a, &b) != 2)
        return 1;

    x = a ^ b;

    while (x != 0) {
        distance += x & 1u;
        x >>= 1;
    }

    printf("Hamming distance = %d\n", distance);
    return 0;
}