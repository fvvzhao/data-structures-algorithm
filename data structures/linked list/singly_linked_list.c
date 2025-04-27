#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* create_linked_list();
void insert(LinkedList* linked_list, int pos, int value);
Node* delete(LinkedList* linked_list, int pos);
void print_linked_list(LinkedList* linked_list);

int main(void) {

    LinkedList* linked_list = create_linked_list();

    return 0;
}

LinkedList* create_linked_list() {
    LinkedList* linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (linked_list == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    linked_list->head = (Node*)malloc(sizeof(Node));
    if (linked_list->head == NULL) {
        puts("内存分配失败");
        free(linked_list);
        return NULL;
    }
    linked_list->head->next = NULL;
    linked_list->size = 0;
    return linked_list;
}

void insert(LinkedList* linked_list, int pos, int value) {
    if (pos < 1 || pos > linked_list->size + 1) {
        puts("插入失败");
        return;
    }
    int t = 0;
    Node* pre = linked_list->head;
    while (t < pos - 1) {
        t++;
        pre = pre->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        puts("内存分配失败");
        free(pre);
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    new_node->next = pre->next;
    pre->next = new_node;
    linked_list->size++;
}

Node* delete(LinkedList* linked_list, int pos) {
    if (pos < 1 || pos > linked_list->size || linked_list->size == 0) {
        puts("删除失败");
        return NULL;
    }
    int t = 0;
    Node* pre = linked_list->head;
    while (t < pos - 1) {
        t++;
        pre = pre->next;
    }
    Node* target = pre->next;
    pre->next = target->next;
    linked_list->size--;
    return target;
}

void print_linked_list(LinkedList* linked_list) {
    Node* t = linked_list->head->next;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}
