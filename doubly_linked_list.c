#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

void insertEnd(int value) {
    Node *newNode = malloc(sizeof(Node));
    Node *temp;

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteValue(int value) {
    Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted.\n");
}

void displayForward(void) {
    Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward(void) {
    Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

void freeList(void) {
    Node *temp = head;

    while (temp != NULL) {
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    head = NULL;
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at end\n");
        printf("2. Delete a value\n");
        printf("3. Display forward\n");
        printf("4. Display backward\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1) {
                    freeList();
                    return 1;
                }

                insertEnd(value);
                break;

            case 2:
                printf("Enter value to delete: ");

                if (scanf("%d", &value) != 1) {
                    freeList();
                    return 1;
                }

                deleteValue(value);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                freeList();
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    freeList();
    return 0;
}
