#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
    Node* top;
} Stack;

Stack* create_stack();
void push(Stack* stack, int value);
Node* pop(Stack* stack);
Node* get_top(Stack* stack);

int main(void) {

    Stack test;
    Stack* ptr = &test;
    create(ptr);

    push(ptr, 1);
    printf("top is %d\n", get_top(ptr)->data);

    return 0;
}

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    stack->head = (Node*)malloc(sizeof(Node));
    if (stack->head == NULL) {
        puts("内存分配失败");
        free(stack);
        return NULL;
    }
    stack->head->next = NULL;
    stack->top = stack->head;
    return stack;
}

void push(Stack* stack, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        puts("内存分配失败");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    new_node->next = stack->top->next;
    stack->top->next = new_node;
}

Node* pop(Stack* stack) {
    if (stack->head->next == NULL) {
        puts("栈已空");
        return NULL;
    }
    Node* target = stack->top->next;
    stack->top->next = target->next;
    return target;
}

Node* get_top(Stack* stack) {
    if (stack->head->next == NULL) {
        puts("栈已空");
        return NULL;
    }
    return stack->top->next;
}
