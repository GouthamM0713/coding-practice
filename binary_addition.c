#include <stdio.h>
#include <string.h>

int main(void) {
    char a[] = "1011";
    char b[] = "1101";
    char result[20];
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    printf("Sum = ");

    while (k > 0)
        printf("%c", result[--k]);

    printf("\n");
    return 0;
}
