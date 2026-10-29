#include <stdio.h>

struct Node {
    char ch;
    int freq;
    int left, right;
};

int main(void) {
    int n, total = 0;
    struct Node nodes[100];

    scanf("%d", &n);
    if (n < 2 || n > 26) return 0;

    for (int i = 0; i < n; i++) {
        scanf(" %c%d", &nodes[i].ch, &nodes[i].freq);
        if (nodes[i].freq <= 0) return 0;
        nodes[i].left = nodes[i].right = -1;
    }

    int active[100], size = n;

    for (int i = 0; i < n; i++)
        active[i] = i;

    while (size > 1) {
        int x = -1, y = -1;

        for (int i = 0; i < size; i++) {
            int k = active[i];

            if (x == -1 || nodes[k].freq < nodes[x].freq) {
                y = x;
                x = k;
            } else if (y == -1 ||
                       nodes[k].freq < nodes[y].freq) {
                y = k;
            }
        }

        nodes[total].ch = '#';
        nodes[total].freq = nodes[x].freq + nodes[y].freq;
        nodes[total].left = x;
        nodes[total].right = y;

        int next[100], p = 0;

        for (int i = 0; i < size; i++)
            if (active[i] != x && active[i] != y)
                next[p++] = active[i];

        next[p++] = total;
        size = p;

        for (int i = 0; i < size; i++)
            active[i] = next[i];

        total++;
    }

    int root = active[0];

    printf("Huffman tree built successfully.\n");
    printf("Root frequency = %d\n", nodes[root].freq);

    return 0;
}