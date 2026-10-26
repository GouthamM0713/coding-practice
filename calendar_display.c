
#include <stdio.h>

int main(void) {
    int month, year;
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    char *months[] = {"January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};

    printf("Enter month and year: ");
    scanf("%d%d", &month, &year);

    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid input\n");
        return 0;
    }

    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0))
        days[1] = 29;

    int y = year;
    int m = month;
    int offset;

    /* Calculate weekday of the first day */
    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    int h = (1 + (13 * (m + 1)) / 5 + k +
             k / 4 + j / 4 + 5 * j) % 7;

    offset = (h + 6) % 7;

    printf("\n%s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < offset; i++)
        printf("    ");

    for (int day = 1; day <= days[month - 1]; day++) {
        printf("%3d ", day);

        if ((offset + day) % 7 == 0)
            printf("\n");
    }

    printf("\n");
    return 0;
}