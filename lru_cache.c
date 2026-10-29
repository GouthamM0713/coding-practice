#include <stdio.h>

int main(void) {
    int n, capacity, pages[100], cache[20];
    int size = 0, faults = 0;

    scanf("%d%d", &n, &capacity);

    if (n < 1 || n > 100 ||
        capacity < 1 || capacity > 20)
        return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < size; j++)
            if (cache[j] == pages[i])
                pos = j;

        if (pos == -1) {
            faults++;

            if (size == capacity) {
                for (int j = 1; j < size; j++)
                    cache[j - 1] = cache[j];
                size--;
            }

            cache[size++] = pages[i];
        } else {
            int page = cache[pos];

            for (int j = pos + 1; j < size; j++)
                cache[j - 1] = cache[j];

            cache[size - 1] = page;
        }

        printf("Page %d: ", pages[i]);

        for (int j = 0; j < size; j++)
            printf("%d ", cache[j]);

        printf("\n");
    }

    printf("Page faults = %d\n", faults);
    return 0;
}