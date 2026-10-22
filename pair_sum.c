#include <stdio.h>

int main(void) {
    int a[] = {2, 4, 6, 8, 10};
    int n = 5, target = 12, found = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == target) {
                printf("%d + %d = %d\n",
                       a[i], a[j], target);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No matching pair found");

    return 0;
}
