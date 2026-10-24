#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

int main() {
    double a, b;
    char op;

    printf("Enter expression (e.g. 5 + 3): ");
    scanf("%lf %c %lf", &a, &op, &b);

    switch (op) {
        case '+': printf("Result = %.2lf", add(a, b)); break;
        case '-': printf("Result = %.2lf", subtract(a, b)); break;
        case '*': printf("Result = %.2lf", multiply(a, b)); break;
        case '/':
            if (b != 0)
                printf("Result = %.2lf", a / b);
            else
                printf("Cannot divide by zero");
            break;
        default: printf("Invalid operator");
    }

    return 0;
}