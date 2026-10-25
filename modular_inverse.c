#include <stdio.h>

int main(void) {
    long long a, m, t = 0, newt = 1;
    long long r, newr;

    printf("Enter a and modulus: ");
    scanf("%lld %lld", &a, &m);

    if (m <= 1) {
        printf("Modulus must be greater than 1\n");
        return 1;
    }

    a = ((a % m) + m) % m;
    r = m;
    newr = a;

    while (newr != 0) {
        long long q = r / newr;
        long long temp = t - q * newt;
        t = newt;
        newt = temp;

        temp = r - q * newr;
        r = newr;
        newr = temp;
    }

    if (r != 1) {
        printf("Modular inverse does not exist\n");
    } else {
        printf("Modular inverse: %lld\n", (t % m + m) % m);
    }

    return 0;
}