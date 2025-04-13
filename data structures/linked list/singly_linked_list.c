#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    struct Node* head;
    int size;
} SinglyLinkedList;

void create(SinglyLinkedList* ptr);
void insert(SinglyLinkedList* ptr, int position, int value);
void delete(SinglyLinkedList* ptr, int position);
void print_linked_list(SinglyLinkedList* ptr);

int main(void) {

    SinglyLinkedList test;
    SinglyLinkedList* ptr = &test;
    create(ptr);

    insert(ptr, 1, 1);
    insert(ptr, 2, 2);
    insert(ptr, 3, 3);
    print_linked_list(ptr);
    return 0;
}

// 带头节点
void create(SinglyLinkedList* ptr) {
    ptr->head = (Node*)malloc(sizeof(Node));
    if (ptr->head == NULL) {
        puts("内存分配失败");
    }
    ptr->head->next = NULL;
    ptr->size = 0;
}

void insert(SinglyLinkedList* ptr, int position, int value) {
    if (position < 1 || position > ptr->size + 1) {
        puts("插入失败");
        return;
    }
    int temp = 0;
    Node* prev = ptr->head;
    while (temp < position - 1) {
        temp++;
        prev = prev->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    new_node->next = prev->next;
    prev->next = new_node;
    ptr->size++;
}

void delete(SinglyLinkedList* ptr, int position) {
    if (position < 1 || position > ptr->size) {
        puts("删除失败");
        return;
    }
    int temp = 0;
    Node* prev = ptr->head;
    while (temp < position - 1) {
        temp++;
        prev = prev->next;
    }
    Node* target = prev->next;
    prev->next = target->next;
    free(target);
    ptr->size--;
}

void print_linked_list(SinglyLinkedList* ptr) {
    Node* temp = ptr->head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
