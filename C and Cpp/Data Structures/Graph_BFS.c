#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue* q) {
    if (q->rear == q->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Queue* q){
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enQueue (struct Queue* q, int val) {
    if (isFull(q))
        printf("\nQueue is Overflow !!!\n");
    else{
        q->rear = q->rear+1;
        q->arr[q->rear] = val;
    }
}

int deQueue (struct Queue* q) {
    int data;
    if (isEmpty(q))
        printf("\nQueue is Empty !!!");
    else {
        q->front = q->front+1;
        data = q->arr[q->front];
    }
    return data;
}

// void traversalBFS ()

int main (){
    struct Queue gQuue;
    gQuue.size = 20;
    gQuue.front = gQuue.rear = -1;
    gQuue.arr = (int *) malloc(gQuue.size * sizeof(int));

    // Graph Initialization and BFS implementation;
    int i = 0;
    int visited[] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    printf("%d ", i);
    visited[i] = 1;
    enQueue(&gQuue, i);  // Enqueue is exploring i;
    while (!isEmpty(&gQuue)) {
        int node = deQueue(&gQuue);
        for (int j = 0; j < 7; j++) {
            if (graph[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enQueue(&gQuue, j);
            }
        }
    }
    
    return 0;
}