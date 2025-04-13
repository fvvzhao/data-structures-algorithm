#include <stdio.h>

#define CAPACITY 10

typedef struct Stack {
    int data[CAPACITY];
    int top;
} Stack;

void create(Stack* ptr);
void push(Stack* ptr, int value);
void pop(Stack* ptr, int* value);
int get_top(Stack* ptr);

int main(void) {

    Stack test;
    Stack* ptr = &test;
    create(ptr);

    push(ptr, 1);
    printf("top is %d\n", get_top(ptr));

    return 0; 
}

void create(Stack* ptr) {
    ptr->top = -1;
}

void push(Stack* ptr, int value) {
    if (ptr->top == CAPACITY - 1) {
        puts("栈已满");
        return;
    }
    ptr->top++;
    ptr->data[ptr->top] = value;
}

void pop(Stack* ptr, int* value) {
    if (ptr->top == -1) {
        puts("栈已空");
        return;
    }
    *value = ptr->data[ptr->top];
    ptr->top--;
}

int get_top(Stack* ptr) {
    if (ptr->top == -1) {
        puts("栈已空");
        return -1;
    }
    return ptr->data[ptr->top];
}
