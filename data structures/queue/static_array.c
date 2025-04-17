#include <stdio.h>

#define CAPACITY 10

typedef struct Queue {
    int data[CAPACITY];
    int size;
    int head;
    int tail;
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
    ptr->size = 0;
    ptr->head = 0;
    ptr->tail = 0;
}

void en_queue(Queue* ptr, int value) {
    if (ptr->size == CAPACITY) {
        puts("队列已满");
        return;
    }
    ptr->data[ptr->tail] = value;
    ptr->tail = (ptr->tail + 1) % CAPACITY;
    ptr->size++;
}

void de_queue(Queue* ptr, int* value) {
    if (ptr->size == 0) {
        puts("队列已空");
        return;
    }
    *value = ptr->data[ptr->head];
    ptr->head = (ptr->head + 1) % CAPACITY;
    ptr->size--;
}

void print_queue(Queue* ptr) {
    int value;
    while (ptr->head != ptr->tail) {
        de_queue(ptr, &value);
        printf("%d ", value);
    }
}
