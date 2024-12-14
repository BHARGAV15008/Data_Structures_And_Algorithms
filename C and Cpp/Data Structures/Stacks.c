#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek element.\n");
        return -1;
    }
    return stack->data[stack->top];
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, value;

    do {
        printf("\n----- Stack Operations ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1) {
                printf("Popped element: %d\n", value);
            }
            break;
        case 3:
            value = peek(&stack);
            if (value != -1) {
                printf("Top element: %d\n", value);
            }
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}