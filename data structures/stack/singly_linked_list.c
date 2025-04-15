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

void create(Stack* ptr);
void push(Stack* ptr, int value);
void pop(Stack* ptr, int* value);
Node* get_top(Stack* ptr);

int main(void) {

    Stack test;
    Stack* ptr = &test;
    create(ptr);

    push(ptr, 1);
    printf("top is %d\n", get_top(ptr)->data);

    return 0;
}

void create(Stack* ptr) {
    ptr->head = (Node*)malloc(sizeof(Node));
    if (ptr->head == NULL) {
        puts("内存分配失败");
        return;
    }
    ptr->head->next = NULL;
    ptr->top = ptr->head;
}

void push(Stack* ptr, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    new_node->next = ptr->top->next;
    ptr->top->next = new_node;
}

void pop(Stack* ptr, int* value) {
    if (ptr->head->next == NULL) {
        puts("栈已空");
        return;
    }
    Node* target = ptr->top->next;
    *value = target->data;
    ptr->top->next = target->next;
    free(target);
}

Node* get_top(Stack* ptr) {
    if (ptr->head->next == NULL) {
        puts("栈已空");
        return NULL;
    }
    return ptr->top->next;
}
