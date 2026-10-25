#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int compare(const void *a, const void *b) {
    const Activity *x = a, *y = b;
    return (x->end > y->end) - (x->end < y->end);
}

int main(void) {
    int n;
    Activity a[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter start and end of activity %d: ", i + 1);
        scanf("%d %d", &a[i].start, &a[i].end);

        if (a[i].start > a[i].end) return 1;
    }

    qsort(a, n, sizeof(Activity), compare);

    int lastEnd = 0, selected = 0;
    int first = 1;

    printf("Selected activities:\n");

    for (int i = 0; i < n; i++) {
        if (first || a[i].start >= lastEnd) {
            printf("(%d, %d)\n", a[i].start, a[i].end);
            lastEnd = a[i].end;
            selected++;
            first = 0;
        }
    }

    printf("Total selected: %d\n", selected);
    return 0;
}