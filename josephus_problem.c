#include <stdio.h>

int main(void) {
    int n, k, survivor = 0;

    printf("Enter number of people and step: ");
    scanf("%d %d", &n, &k);

    if (n <= 0 || k <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
        survivor = (survivor + k) % i;

    printf("Survivor position: %d\n", survivor + 1);
    return 0;
}