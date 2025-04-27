#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct Stack {
    int data[CAPACITY];
    int top;
} Stack;

Stack* create_stack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int get_top(Stack* stack);

int main(void) {

    Stack* stack = create_stack();

    return 0; 
}

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == CAPACITY - 1) {
        puts("栈已满");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        puts("栈已空");
        return -1;
    }
    int t = stack->data[stack->top];
    stack->top--;
    return t;
}

int get_top(Stack* stack) {
    if (stack->top == -1) {
        puts("栈已空");
        return -1;
    }
    return stack->data[stack->top];
}
