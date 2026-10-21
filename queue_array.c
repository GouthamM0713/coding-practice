#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0, count = 0;

void enqueue(int value) {
    if (count == SIZE) {
        printf("Queue is full.\n");
        return;
    }

    queue[rear] = value;
    rear = (rear + 1) % SIZE;
    count++;
}

void dequeue(void) {
    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display(void) {
    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++)
        printf("%d ", queue[(front + i) % SIZE]);

    printf("\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n1.Enqueue  2.Dequeue  3.Display  0.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
