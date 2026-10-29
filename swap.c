
#include <stdio.h>

<<<<<<< HEAD
int main(void) {
    int a, b, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
=======
int main() {
    int a = 10, b = 20, temp;

    printf("Before swapping: a = %d, b = %d\n", a, b);
>>>>>>> edec9d024a3c15cbbdf52562f3f00e3414b54b5f

    temp = a;
    a = b;
    b = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
