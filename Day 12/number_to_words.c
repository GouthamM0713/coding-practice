#include <stdio.h>

char *ones[] = {
    "Zero", "One", "Two", "Three", "Four",
    "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen",
    "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};

char *tens[] = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

void words(int n) {
    if (n >= 1000) {
        words(n / 1000);
        printf(" Thousand");
        n %= 1000;
    }

    if (n >= 100) {
        printf(" %s Hundred", ones[n / 100]);
        n %= 100;
    }

    if (n >= 20) {
        printf(" %s", tens[n / 10]);
        n %= 10;
    }

    if (n > 0)
        printf(" %s", ones[n]);
}

int main(void) {
    int n;

    printf("Enter number (0-9999): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 9999) {
        printf("Invalid input\n");
        return 1;
    }

    if (n == 0)
        printf("Zero");
    else
        words(n);

    printf("\n");
    return 0;
}