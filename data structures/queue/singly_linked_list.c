#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void create(Queue* ptr);
void en_queue(Queue* ptr, int value);
void de_queue(Queue* ptr, int* value);
void print_queue(Queue* ptr);

int main(void) {

    Queue test;
    Queue* ptr = &test;
    create(ptr);

    en_queue(ptr, 1);
    en_queue(ptr, 2);
    en_queue(ptr, 3);
    en_queue(ptr, 4);
    en_queue(ptr, 5);

    print_queue(ptr);
    return 0;
}

void create(Queue* ptr) {
    ptr->head = (Node*)malloc(sizeof(Node));
    if (ptr->head == NULL) {
        puts("内存分配失败");
        return;
    }
    ptr->head->next = NULL;
    ptr->tail = ptr->head;
}

void en_queue(Queue* ptr, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    ptr->tail->next = new_node;
    ptr->tail = new_node;
}

void de_queue(Queue* ptr, int* value) {
    if (ptr->head == ptr->tail) {
        puts("队列已空");
        return;
    }
    Node* target = ptr->head->next;
    *value = target->data;
    ptr->head->next = target->next;
    if (target == ptr->tail) {
        free(target);
        ptr->tail = ptr->head;
    }
    else {
        free(target);
    }
}

void print_queue(Queue* ptr) {
    int value;
    while (ptr->head != ptr->tail) {
        de_queue(ptr, &value);
        printf("%d ", value);
    }
}
