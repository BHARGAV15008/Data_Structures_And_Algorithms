#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    return data;
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    int choice, data;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
