#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *table[SIZE];

void insert(int x) {
    int index = ((x % SIZE) + SIZE) % SIZE;

    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = table[index];

    table[index] = p;
}

int search(int x) {
    int index = ((x % SIZE) + SIZE) % SIZE;

    struct Node *p = table[index];

    while (p) {
        if (p->data == x)
            return 1;

        p = p->next;
    }

    return 0;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);

        struct Node *p = table[i];

        while (p) {
            printf("%d -> ", p->data);
            p = p->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int n, x, key;

    scanf("%d", &n);

    if (n < 0 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    display();

    scanf("%d", &key);

    if (search(key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}