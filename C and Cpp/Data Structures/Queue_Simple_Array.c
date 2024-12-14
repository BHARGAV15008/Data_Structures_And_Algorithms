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

int main (){
    struct Queue quue;
    quue.size = 10;
    quue.front = quue.rear = -1;
    quue.arr = (int *) malloc(quue.size * sizeof(int));
    enQueue(&quue, 23);
    enQueue(&quue, 34);
    enQueue(&quue, 45);
    enQueue(&quue, 56);
    enQueue(&quue, 67);
    enQueue(&quue, 68);
    enQueue(&quue, 69);
    enQueue(&quue, 77);
    enQueue(&quue, 78);
    enQueue(&quue, 79);
    enQueue(&quue, 79);
    printf("\n%d ", deQueue(&quue));
    printf("\n%d ", deQueue(&quue));
    printf("\n%d ", deQueue(&quue));

    return 0;
}