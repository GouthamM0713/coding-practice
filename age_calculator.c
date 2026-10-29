
#include <stdio.h>

int leap(int y) {
    return y % 400 == 0 ||
          (y % 4 == 0 && y % 100 != 0);
}

int monthDays(int m, int y) {
    int d[] = {31, 28, 31, 30, 31, 30,
               31, 31, 30, 31, 30, 31};

    if (m == 2 && leap(y))
        return 29;

    return d[m - 1];
}

int validDate(int d, int m, int y) {
    return y >= 1 && m >= 1 && m <= 12 &&
           d >= 1 && d <= monthDays(m, y);
}

int main(void) {
    int bd, bm, by, td, tm, ty;

    printf("Enter birth date (DD MM YYYY): ");
    scanf("%d%d%d", &bd, &bm, &by);

    printf("Enter current date (DD MM YYYY): ");
    scanf("%d%d%d", &td, &tm, &ty);

    if (!validDate(bd, bm, by) ||
        !validDate(td, tm, ty)) {
        printf("Invalid date\n");
        return 0;
    }

    if (by > ty || (by == ty && bm > tm) ||
        (by == ty && bm == tm && bd > td)) {
        printf("Birth date is in the future\n");
        return 0;
    }

    if (td < bd) {
        tm--;
        if (tm == 0) {
            tm = 12;
            ty--;
        }
        td += monthDays(tm, ty);
    }

    if (tm < bm) {
        tm += 12;
        ty--;
    }

    printf("Age = %d years, %d months, %d days\n",
           ty - by, tm - bm, td - bd);

    return 0;
}