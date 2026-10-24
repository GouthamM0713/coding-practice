#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *rear = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 1) {
            Node *newNode = malloc(sizeof(Node));

            if (newNode == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }

            printf("Enter value: ");

            if (scanf("%d", &value) != 1) {
                free(newNode);
                break;
            }

            newNode->data = value;

            if (rear == NULL) {
                newNode->next = newNode;
            } else {
                newNode->next = rear->next;
                rear->next = newNode;
            }

            rear = newNode;
            printf("Element inserted.\n");

        } else if (choice == 2) {
            Node *front;

            if (rear == NULL) {
                printf("Queue is empty.\n");
                continue;
            }

            front = rear->next;

            printf("Deleted element: %d\n", front->data);

            if (front == rear) {
                rear = NULL;
            } else {
                rear->next = front->next;
            }

            free(front);

        } else if (choice == 3) {
            Node *current;

            if (rear == NULL) {
                printf("Queue is empty.\n");
                continue;
            }

            current = rear->next;

            printf("Queue elements: ");

            do {
                printf("%d ", current->data);
                current = current->next;
            } while (current != rear->next);

            printf("\n");

        } else if (choice == 4) {
            break;

        } else {
            printf("Invalid choice.\n");
        }
    }

    if (rear != NULL) {
        Node *current = rear->next;
        rear->next = NULL;

        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}