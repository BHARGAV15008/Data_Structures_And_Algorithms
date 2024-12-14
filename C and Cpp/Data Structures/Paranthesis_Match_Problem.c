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

void paranthesisCheck(char *str) {
    int status = 0;
    struct Stack stacks;
    stacks.top = -1;
    stacks.size = 20;
    stacks.arr = (int *) malloc(stacks.size * sizeof(int));

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(&stacks, str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if (stacks.top == -1){
                status = 1;
                break;
            }

            if ((str[i] == ')' && stacks.arr[stacks.top] == '(') || 
            (str[i] == ']' && stacks.arr[stacks.top] == '[') || 
            (str[i] == '}' && stacks.arr[stacks.top] == '{')) {
                pop(&stacks);
            }
        }
        else
            continue;
    }

    if (stacks.top == -1 && status == 0){
        printf("Your equation/Code is good and Paranthesis balanced.....");
    }
    else
        printf("Paranthesis Unbalanced.....");
}

int main (){
    char *str;
    str = "[(2+5)]";
    paranthesisCheck(str);
    
    return 0;
}