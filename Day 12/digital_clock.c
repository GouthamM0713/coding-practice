#include <stdio.h>

int main(void) {
    int h, m, s;

    printf("Enter hours minutes seconds: ");
    if (scanf("%d%d%d", &h, &m, &s) != 3 ||
        h < 0 || h > 23 ||
        m < 0 || m > 59 ||
        s < 0 || s > 59) {
        printf("Invalid time\n");
        return 1;
    }

    s++;

    if (s == 60) {
        s = 0;
        m++;
    }

    if (m == 60) {
        m = 0;
        h++;
    }

    if (h == 24)
        h = 0;

    printf("Next time: %02d:%02d:%02d\n", h, m, s);
    return 0;
}