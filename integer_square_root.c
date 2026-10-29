#include <stdio.h>

int main(void) {
    long long n, low = 0, high, mid, answer = 0;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    high = n / 2 + 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (mid == 0 || mid <= n / mid) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Integer square root = %lld\n", answer);
    return 0;
}