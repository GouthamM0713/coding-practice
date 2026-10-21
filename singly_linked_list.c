#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    struct Node *head = NULL, *tail = NULL, *node;
    int n, value;

    printf("How many nodes? ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Invalid count.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        node = malloc(sizeof(struct Node));

        if (node == NULL) {
            printf("Memory allocation failed.\n");
            while (head != NULL) {
                node = head;
                head = head->next;
                free(node);
            }
            return 1;
        }

        node->data = value;
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    printf("Linked list: ");

    for (node = head; node != NULL; node = node->next)
        printf("%d -> ", node->data);

    printf("NULL\n");

    while (head != NULL) {
        node = head;
        head = head->next;
        free(node);
    }

    return 0;
}
