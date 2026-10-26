
#include <stdio.h>
#include <math.h>

int main(void) {
    double principal, rate, amount;
    int years;

    printf("Enter principal amount: ");
    scanf("%lf", &principal);

    printf("Enter annual interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    if (principal < 0 || rate < 0 || years < 0) {
        printf("Invalid input\n");
        return 0;
    }

    amount = principal * pow(1 + rate / 100, years);

    printf("Final amount = %.2f\n", amount);
    printf("Compound interest = %.2f\n",
           amount - principal);

    return 0;
}