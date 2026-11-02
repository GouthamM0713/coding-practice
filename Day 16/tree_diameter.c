#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *root) {
    if (!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}

int diameter(struct Node *root) {
    if (!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    int d1 = diameter(root->left);
    int d2 = diameter(root->right);

    return max(l + r + 1, max(d1, d2));
}

struct Node *create(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

int main() {
    struct Node *root = create(1);

    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Diameter = %d nodes", diameter(root));

    return 0;
}