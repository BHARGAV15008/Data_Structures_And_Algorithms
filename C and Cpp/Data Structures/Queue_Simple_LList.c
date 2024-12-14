#include <stdio.h>
#include <stdlib.h>

struct Queue *f = NULL;
struct Queue *r = NULL;

struct Queue {
    int data;
    struct Queue* next;
};

void enQueue (int val) {
    struct Queue*  cNode = (struct Queue*) malloc(sizeof(struct Queue));
    if (cNode == NULL)
        printf("\nQueue is Full\n");
    else {
        cNode->data = val;
        cNode->next = NULL;
        if (f == NULL)
            f = r = cNode;
        else{
            r->next = cNode;
            r = cNode;
        }
    }
}

int deQueue () {
    int data = -1;
    struct Queue* cNode = f;
    if (f == NULL)
        printf("Queue is Empty...\n");
    else{
        f = f->next;
        data = cNode->data;
        free(cNode);
    }
    return data;
}

void traversalQueue (struct Queue* ptr){
    struct Queue* nNode = ptr;
    printf("\nQueue element is \n");
    while(nNode != NULL){
        printf("%d | ", nNode->data);
        nNode = nNode->next;
    }
}

int main (){
    enQueue(34);
    enQueue(35);
    enQueue(36);
    enQueue(37);
    printf("\nDequeue data is %d", deQueue());
    traversalQueue(f);
    printf("\nDequeue data is %d", deQueue());
    traversalQueue(f);
    
    return 0;
}