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

Queue* create_queue();
void en_queue(Queue* q, int value);
Node* de_queue(Queue* q);
void print_queue(Queue* q);

int main(void) {

    Queue* q = create_queue();

    en_queue(q, 1);
    en_queue(q, 2);
    en_queue(q, 3);
    en_queue(q, 4);
    en_queue(q, 5);

    print_queue(q);
    return 0;
}

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        puts("内存分配失败"); 
        return NULL;
    }
    q->head = (Node*)malloc(sizeof(Node));
    if (q->head == NULL) {
        puts("内存分配失败");
        free(q);
        return NULL;
    }
    q->head->next = NULL;
    q->tail = q->head;
    return q;
}

void en_queue(Queue* q, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        puts("内存分配失败");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    q->tail->next = new_node;
    q->tail = new_node;
}

Node* de_queue(Queue* q) {
    if (q->head == q->tail) {
        puts("队列已空");
        return NULL;
    }
    Node* target = q->head->next;
    q->head->next = target->next;
    if (target == q->tail) {
        q->tail = q->head;
        return target;
    }
    else {
        return target;
    }
}

void print_queue(Queue* q) {
    Node* t = q->head->next;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}
