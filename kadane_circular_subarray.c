#include <stdio.h>

int main(void) {
    int a[100], n, i;
    long long total, maxEnd, maxSum;
    long long minEnd, minSum;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    total = maxEnd = maxSum = a[0];
    minEnd = minSum = a[0];

    for (i = 1; i < n; i++) {
        if (maxEnd + a[i] < a[i])
            maxEnd = a[i];
        else
            maxEnd += a[i];

        if (maxEnd > maxSum)
            maxSum = maxEnd;

        if (minEnd + a[i] > a[i])
            minEnd = a[i];
        else
            minEnd += a[i];

        if (minEnd < minSum)
            minSum = minEnd;

        total += a[i];
    }

    if (maxSum < 0) {
        printf("Maximum circular subarray sum = %lld\n", maxSum);
    } else {
        long long circularSum = total - minSum;

        if (circularSum > maxSum)
            maxSum = circularSum;

        printf("Maximum circular subarray sum = %lld\n", maxSum);
    }

    return 0;
}