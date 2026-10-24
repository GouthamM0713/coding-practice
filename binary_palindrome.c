#include <stdio.h>

int main(void) {
    unsigned int n, temp, reversed = 0;

    printf("Enter a non-negative integer: ");
    if (scanf("%u", &n) != 1)
        return 1;

    temp = n;

    while (temp > 0) {
        reversed = (reversed << 1) | (temp & 1u);
        temp >>= 1;
    }

    if (n == reversed)
        printf("Binary representation is a palindrome.\n");
    else
        printf("Binary representation is not a palindrome.\n");

    return 0;
}