#include <stdio.h>

struct Item {
    int weight, value;
    double ratio;
};

int main(void) {
    int n, capacity;
    struct Item a[50];
    double profit = 0;

    scanf("%d%d", &n, &capacity);

    if (n < 1 || n > 50 || capacity < 0)
        return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].weight, &a[i].value);

        if (a[i].weight <= 0 || a[i].value < 0)
            return 0;

        a[i].ratio = (double)a[i].value / a[i].weight;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j].ratio > a[i].ratio) {
                struct Item t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    for (int i = 0; i < n && capacity > 0; i++) {
        if (a[i].weight <= capacity) {
            capacity -= a[i].weight;
            profit += a[i].value;
        } else {
            profit += a[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", profit);
    return 0;
}