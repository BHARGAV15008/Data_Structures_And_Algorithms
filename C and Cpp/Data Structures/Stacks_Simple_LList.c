#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

int isEmpty(struct Stack* s) {
    if (s == NULL)
        return 1;
    else
        return 0;
}

int isFull (struct Stack* s) {
    struct Stack* node = (struct Stack *) malloc(sizeof(struct Stack));
    if (node == NULL)
        return 1;
    else
        return 0;
}

struct Stack* push (struct Stack* s, int data) {
    struct Stack* sn = (struct Stack*) malloc(sizeof(struct Stack));
    if (isFull(s))
        printf("Stack is overflow.....");
    else{
        sn->data = data;
        sn->next = s;
        s = sn;
        return s;
    }
}

struct Stack* pop (struct Stack* s) {
    if (isEmpty(s))
        printf("Stack is Empty.....");
    else{
        struct Stack *sn = s;
        s = s->next;
        free(sn);
        return s;
    }
}

void traversalStack (struct Stack* s) {
    while (s != NULL){
        printf("%d | ", s->data);
        s = s->next;
    }
}

int main (){
    struct Stack *stacks;
    stacks->data = 5;
    stacks->next = NULL;
    stacks = push(stacks, 12);
    stacks = push(stacks, 13);
    stacks = push(stacks, 14);
    stacks = push(stacks, 15);
    stacks = push(stacks, 16);
    traversalStack(stacks);
    stacks = pop(stacks);
    printf("\n");
    traversalStack(stacks);
    
    return 0;
}