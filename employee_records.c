#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee e[50];
    int n, i;

    printf("Enter number of employees (1-50): ");
    scanf("%d", &n);

    if (n < 1 || n > 50)
        return 0;

    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &e[i].id);

        printf("Enter name (one word): ");
        scanf("%49s", e[i].name);

        printf("Enter salary: ");
        scanf("%f", &e[i].salary);
    }

    printf("\nEmployee Records\n");

    for (i = 0; i < n; i++) {
        printf("\nID: %d\n", e[i].id);
        printf("Name: %s\n", e[i].name);
        printf("Salary: %.2f\n", e[i].salary);
    }

    return 0;
}