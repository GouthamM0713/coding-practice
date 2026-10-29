#include <stdio.h>

void hanoi(int n, char from, char aux, char to) {
    if (n == 0) return;

    hanoi(n - 1, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, from, to);
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Enter disks from 1 to 20\n");
        return 0;
    }

    hanoi(n, 'A', 'B', 'C');
    return 0;
}