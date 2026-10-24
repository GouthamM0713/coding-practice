#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main(void) {
    int a = 12, b = 4;
    int (*operation)(int, int);

    operation = add;
    printf("Addition = %d\n", operation(a, b));

    operation = subtract;
    printf("Subtraction = %d\n", operation(a, b));

    operation = multiply;
    printf("Multiplication = %d\n", operation(a, b));

    return 0;
}
