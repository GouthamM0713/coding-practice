
#include <stdio.h>

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int isPalindrome(int n) {
    int original = n, reverse = 0;

    while (n > 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return original == reverse;
}

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 0 && isPrime(n) && isPalindrome(n))
        printf("Prime palindrome\n");
    else
        printf("Not a prime palindrome\n");

    return 0;
}