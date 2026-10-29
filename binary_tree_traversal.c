#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int value) {
    Node *p = malloc(sizeof(Node));
    if (!p) exit(1);

    p->data = value;
    p->left = p->right = NULL;
    return p;
}

void inorder(Node *p) {
    if (!p) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

void preorder(Node *p) {
    if (!p) return;
    printf("%d ", p->data);
    preorder(p->left);
    preorder(p->right);
}

void postorder(Node *p) {
    if (!p) return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->data);
}

void freeTree(Node *p) {
    if (!p) return;
    freeTree(p->left);
    freeTree(p->right);
    free(p);
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    freeTree(root);
    return 0;
}