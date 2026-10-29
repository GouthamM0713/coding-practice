#include <stdio.h>
#include <string.h>

int main(void) {
    char a[200], b[200];
    int i = 0, j = 0, equal = 1;

    printf("Enter first string: ");
    scanf("%199s", a);

    printf("Enter second string: ");
    scanf("%199s", b);

    while (a[i] && b[j]) {
        char ca = a[i], cb = b[j];
        int countA = 0, countB = 0;

        while (a[i] == ca && a[i]) {
            countA++;
            i++;
        }

        while (b[j] == cb && b[j]) {
            countB++;
            j++;
        }

        if (ca != cb || countA != countB) {
            equal = 0;
            break;
        }
    }

    if (a[i] || b[j])
        equal = 0;

    if (equal)
        printf("Strings have identical run-length encoding\n");
    else
        printf("Strings have different run-length encoding\n");

    return 0;
}