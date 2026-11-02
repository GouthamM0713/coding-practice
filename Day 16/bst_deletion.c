#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

struct Node *insert(struct Node *root, int x) {
    if (!root) return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct Node *minimum(struct Node *root) {
    while (root && root->left)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int x) {
    if (!root) return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (!root->left) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (!root->right) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, x, key;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("After deletion: ");
    inorder(root);

    return 0;
}