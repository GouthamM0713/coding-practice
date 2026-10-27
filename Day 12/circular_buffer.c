#include <stdio.h>

#define SIZE 5

int main(void) {
    int a[SIZE], front = 0, rear = -1, count = 0;
    int choice, value;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        if (choice == 1) {
            if (count == SIZE) {
                printf("Buffer full\n");
            } else {
                printf("Enter value: ");
                if (scanf("%d", &value) != 1)
                    return 1;

                rear = (rear + 1) % SIZE;
                a[rear] = value;
                count++;
            }
        } else if (choice == 2) {
            if (count == 0) {
                printf("Buffer empty\n");
            } else {
                printf("Deleted: %d\n", a[front]);
                front = (front + 1) % SIZE;
                count--;
            }
        } else if (choice == 3) {
            if (count == 0) {
                printf("Buffer empty\n");
            } else {
                for (int i = 0; i < count; i++)
                    printf("%d ", a[(front + i) % SIZE]);
                printf("\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}