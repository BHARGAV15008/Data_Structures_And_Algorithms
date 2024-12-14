#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

void push (struct Stack* s, int data) {
    if (s->top == s->size)
        printf("Your stack is full!!!");
    s->arr[++(s->top)] = data;
}

int pop (struct Stack* s) {
    int data = 0;
    if (s->top == -1){
        printf("Your stack is Empty.....");
        return 0;
    }
    else
        data = s->arr[s->top];
    (s->top)--;
    
    return data;
}

int peek (struct Stack* s, int index) {
    int data;
    if (s->top - index + 1 < 0){
        printf("Invalid Position...");
        return -1;
    }
    data = s->arr[s->top - index + 1];
    return data;
}

void traversalStacks (struct Stack* s) {
    int i = s->top;
    while (i >= 0){
        printf("|    |\n");
        printf("| %d |\n", s->arr[i]);
        printf("|____|\n");
        i--;
    }
}

int main (){
    struct Stack stacks;
    stacks.top = -1;
    stacks.size = 10;
    stacks.arr = (int *) malloc(stacks.size * sizeof(int));
    push(&stacks, 23);
    push(&stacks, 24);
    push(&stacks, 27);
    push(&stacks, 28);
    push(&stacks, 33);
    push(&stacks, 34);
    push(&stacks, 37);
    push(&stacks, 38);
    traversalStacks(&stacks);
    pop(&stacks);
    pop(&stacks);
    printf("\n\n");
    traversalStacks(&stacks);
    printf("\n%d", peek(&stacks, 4));
    
    return 0;
}