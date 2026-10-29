#include <stdio.h>

struct Job {
    char id;
    int deadline, profit;
};

int main(void) {
    int n, maxDeadline = 0, total = 0;
    struct Job jobs[50];
    int slot[51] = {0};

    scanf("%d", &n);
    if (n < 1 || n > 50) return 0;

    for (int i = 0; i < n; i++) {
        scanf(" %c%d%d",
              &jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);

        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (jobs[j].profit > jobs[i].profit) {
                struct Job t = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = t;
            }

    if (maxDeadline > 50) maxDeadline = 50;

    for (int i = 0; i < n; i++) {
        int d = jobs[i].deadline;

        if (d > maxDeadline) d = maxDeadline;

        for (int j = d; j >= 1; j--) {
            if (!slot[j] && jobs[i].profit > 0) {
                slot[j] = i + 1;
                total += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled jobs: ");

    for (int i = 1; i <= maxDeadline; i++)
        if (slot[i])
            printf("%c ", jobs[slot[i] - 1].id);

    printf("\nTotal profit = %d\n", total);
    return 0;
}