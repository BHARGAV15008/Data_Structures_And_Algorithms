#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

void push (struct Stack* s, char data) {
    if (s->top == s->size)
        printf("Your stack is full!!!");
    s->arr[++(s->top)] = data;
}

char pop (struct Stack* s) {
    char data;
    if (s->top == -1){
        printf("Your stack is Empty.....");
        return 0;
    }
    else
        data = s->arr[s->top];
    (s->top)--;
    
    return data;
}

int isOperator (char op) {
    char *ops = "-+/*^(){}[]";
    int i = 0;
    while (ops[i] != '\0'){
        if (ops[i] == op)
            return 1;
        i++;
    }
    return 0;
}

int operatorPrecedence (char a) {
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '^')
        return 3;
    else if (a == '(' || a == ')')
        return 4;
    else if (a == '[' || a == ']')
        return 5;
    else if (a == '{' || a == '}')
        return 6;
    else
        return 0;
}

void traversalStacks (struct Stack* s) {
    int i = s->top;
    while (i >= 0){
        printf("|    |\n");
        printf("| %c  |\n", s->arr[i]);
        printf("|____|\n");
        i--;
    }
}

char* infixToPostfix (char infix[]) {
    char *postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    struct Stack stacks;
    stacks.top = -1;
    stacks.size = 10;
    stacks.arr = (int *) malloc((stacks.size) * sizeof(int));
    int k = 0, i = 0;
    while (infix[i] != '\0') {
        if (!isOperator(infix[i]))
            postfix[k++] = infix[i++];
        else {
            if (operatorPrecedence(infix[i]) > operatorPrecedence(stacks.arr[stacks.top]))
                push(&stacks, infix[i++]);
            else {
                if (infix[i] != ')' || infix[i] != ']' || infix[i] != '}'){
                    while ((operatorPrecedence(infix[i]) <= operatorPrecedence(stacks.arr[stacks.top]))){
                        postfix[k++] = stacks.arr[stacks.top];
                        pop(&stacks);
                        push(&stacks, infix[i++]);
                        }
                    }
                else{
                    while ((infix[i] == '}' && stacks.arr[stacks.top] == '{') || 
                    (infix[i] == ']' && stacks.arr[stacks.top] == '[') || 
                    (infix[i] == ')' && stacks.arr[stacks.top] == '(')){
                        pop(&stacks);
                        i++;
                    }
                }
            }
        }
    }
    while (stacks.top != -1)
        postfix[k++] = pop(&stacks);
    postfix[k++] = '\0';

    return postfix;
}

int main (){
    char infix[] = "1+4";
    char *postfix;

    postfix = infixToPostfix(infix);

    printf("%s", postfix);
    
    return 0;
}