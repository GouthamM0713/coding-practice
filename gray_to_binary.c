#include <stdio.h>

int main(void) {
    unsigned int gray, binary;
    printf("Enter Gray code as an integer: ");
    scanf("%u", &gray);

    binary = 0;
    for (; gray; gray >>= 1)
        binary ^= gray;

    printf("Binary value: %u\n", binary);
    return 0;
}