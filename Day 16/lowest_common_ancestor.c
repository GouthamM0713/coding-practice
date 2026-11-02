#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int x) {
    if (!root) {
        struct Node *p = malloc(sizeof(struct Node));
        p->data = x;
        p->left = p->right = NULL;
        return p;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct Node *lca(struct Node *root, int a, int b) {
    if (!root) return NULL;

    if (a < root->data && b < root->data)
        return lca(root->left, a, b);

    if (a > root->data && b > root->data)
        return lca(root->right, a, b);

    return root;
}

int exists(struct Node *root, int x) {
    while (root) {
        if (root->data == x) return 1;

        root = x < root->data
            ? root->left : root->right;
    }

    return 0;
}

int main() {
    struct Node *root = NULL;
    int n, x, a, b;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d%d", &a, &b);

    if (!exists(root, a) || !exists(root, b)) {
        printf("Node not found");
        return 0;
    }

    struct Node *ans = lca(root, a, b);

    printf("LCA = %d", ans->data);

    return 0;
}