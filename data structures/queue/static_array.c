#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct Queue {
    int data[CAPACITY];
    int size;
    int head;
    int tail;
} Queue;

Queue* create_queue();
void en_queue(Queue* q, int value);
int de_queue(Queue* q);
void print_queue(Queue* ptr);

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
    Queue* ptr = (Queue*)malloc(sizeof(Queue));
    if (ptr == NULL) {
        puts("内存分配失败"); 
        return NULL;
    }
    ptr->size = 0;
    ptr->head = 0;
    ptr->tail = 0;
    return ptr;
}

void en_queue(Queue* q, int value) {
    if (q->size == CAPACITY) {
        puts("队列已满");
        return;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % CAPACITY;
    q->size++;
}

int de_queue(Queue* q) {
    if (q->size == 0) {
        puts("队列已空");
        return -1;
    }
    int t = q->data[q->head];
    q->head = (q->head + 1) % CAPACITY;
    q->size--;
    return t;
}

void print_queue(Queue* ptr) {
    for (int i = ptr->head; i != ptr->tail; i = (i + 1) % CAPACITY) {
        printf("%d ", ptr->data[i]);
    }
}
