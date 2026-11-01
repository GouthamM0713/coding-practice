#include <stdio.h>
#include <stdlib.h>

struct Trie {
    struct Trie *child[26];
    int end;
};

struct Trie *create() {
    struct Trie *t = calloc(1, sizeof(struct Trie));
    return t;
}

void insert(struct Trie *root, char *word) {
    struct Trie *p = root;

    for (int i = 0; word[i]; i++) {
        int x = word[i] - 'a';

        if (x < 0 || x >= 26) return;

        if (!p->child[x])
            p->child[x] = create();

        p = p->child[x];
    }

    p->end = 1;
}

int search(struct Trie *root, char *word) {
    struct Trie *p = root;

    for (int i = 0; word[i]; i++) {
        int x = word[i] - 'a';

        if (x < 0 || x >= 26 || !p->child[x])
            return 0;

        p = p->child[x];
    }

    return p->end;
}

int main() {
    struct Trie *root = create();
    int n;
    char word[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%99s", word);
        insert(root, word);
    }

    scanf("%99s", word);

    if (search(root, word))
        printf("Word found");
    else
        printf("Word not found");

    return 0;
}