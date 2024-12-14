#include <stdio.h>
#define MAX_SIZE 5

// Structure for circular queue
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function prototypes
void initQueue(CircularQueue* queue);
int isFull(CircularQueue* queue);
int isEmpty(CircularQueue* queue);
void enqueue(CircularQueue* queue, int item);
int dequeue(CircularQueue* queue);
void display(CircularQueue* queue);

int main() {
    CircularQueue queue;
    initQueue(&queue);

    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;

            case 2:
                if (!isEmpty(&queue)) {
                    item = dequeue(&queue);
                    printf("Dequeued element: %d\n", item);
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void initQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    printf("Enqueued element: %d\n", item);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        // Queue becomes empty after dequeueing
        initQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return item;
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d, ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}
