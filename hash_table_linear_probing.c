#include <stdio.h>

#define SIZE 11

int main(void) {
    int table[SIZE], n, key;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("How many keys (maximum %d)? ", SIZE);
    scanf("%d", &n);

    if (n < 0 || n > SIZE) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);

        int index = ((key % SIZE) + SIZE) % SIZE;
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        if (table[index] == -1)
            table[index] = key;
        else
            printf("Hash table is full\n");
    }

    printf("\nHash table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d] Empty\n", i);
        else
            printf("[%d] %d\n", i, table[i]);
    }

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    int index = ((key % SIZE) + SIZE) % SIZE;
    int start = index, found = 0;

    while (table[index] != -1) {
        if (table[index] == key) {
            found = 1;
            break;
        }

        index = (index + 1) % SIZE;
        if (index == start) break;
    }

    if (found)
        printf("Key found at index %d\n", index);
    else
        printf("Key not found\n");

    return 0;
}