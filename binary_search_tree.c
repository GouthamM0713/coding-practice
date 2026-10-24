#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate values are not inserted.\n");

    return root;
}

Node *search(Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display inorder\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 1) {
            printf("Enter value: ");

            if (scanf("%d", &value) != 1)
                break;

            root = insert(root, value);

        } else if (choice == 2) {
            printf("Enter value to search: ");

            if (scanf("%d", &value) != 1)
                break;

            if (search(root, value) != NULL)
                printf("Value found.\n");
            else
                printf("Value not found.\n");

        } else if (choice == 3) {
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");

        } else if (choice == 4) {
            break;

        } else {
            printf("Invalid choice.\n");
        }
    }

    freeTree(root);
    return 0;
}