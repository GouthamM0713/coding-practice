#include <stdio.h>

int main(void) {
    int n;
    long long reverse = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Not a palindrome\n");
        return 0;
    }

    int temp = n;

    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    if (n == reverse) {
        printf("Palindrome number\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
