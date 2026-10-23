
#include <stdio.h>

<<<<<<< HEAD
int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
=======
int main() {
    int n = 8;
>>>>>>> edec9d024a3c15cbbdf52562f3f00e3414b54b5f

    if (n % 2 == 0) {
        printf("Even number\n");
    } else {
        printf("Odd number\n");
    }

    return 0;
}
