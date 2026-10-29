#include <stdio.h>

int main(void) {
    int n = 144;
    int i = 0;

    while (i <= n / (i + 1)) {
        i++;
    }

    if (i * i == n)
        printf("%d is a perfect square", n);
    else
        printf("%d is not a perfect square", n);

    return 0;
}
