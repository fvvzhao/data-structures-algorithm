#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

typedef struct Queue {
    Node* data[CAPACITY];
    int head;
    int tail;
    int size;
} Queue;

void create_binary_tree(BinaryTree* ptr, char value);
Node* create_node(char value);
void pre_order(Node* root);
void in_order(Node* root);
void post_order(Node* root);
void create_queue(Queue* ptr);
void en_queue(Queue* ptr, Node* new_node);
Node* de_queue(Queue* ptr);
void level_order(Node* root);

int main(void) {

    BinaryTree test;
    BinaryTree* ptr = &test;
    create_binary_tree(ptr, 'A');
    ptr->root->lchild = create_node('B');
    ptr->root->rchild = create_node('C');
    ptr->root->lchild->lchild = create_node('D');
    ptr->root->lchild->rchild = create_node('E');
    ptr->root->rchild->lchild = create_node('F');
    ptr->root->rchild->rchild = create_node('G');
    
    puts("先序遍历：");
    pre_order(ptr->root);
    printf("\n");
    puts("中序遍历：");
    in_order(ptr->root);
    printf("\n");
    puts("后序遍历：");
    post_order(ptr->root);
    printf("\n");
    puts("层序遍历：");
    level_order(ptr->root);
    return 0;
}

void create_binary_tree(BinaryTree* ptr, char value) {
    ptr->root = (Node*)malloc(sizeof(Node));
    if (ptr == NULL) {
        puts("内存分配失败");
        return;
    }
    ptr->root->data = value;
    ptr->root->lchild = NULL;
    ptr->root->rchild = NULL;
}

Node* create_node(char value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

void pre_order(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}

void in_order(Node* root) {
    if (root != NULL) {
        in_order(root->lchild);
        printf("%c ", root->data);
        in_order(root->rchild);
    }
}

void post_order(Node* root) {
    if (root != NULL) {
        post_order(root->lchild);
        post_order(root->rchild);
        printf("%c ", root->data);
    }
}

void create_queue(Queue* ptr) {
    ptr->head = 0;
    ptr->tail = 0;
    ptr->size = 0;
}

void en_queue(Queue* ptr, Node* new_node) {
    if (ptr->size == CAPACITY) {
        puts("队列已满");
        return;
    }
    if (new_node == NULL) {
        puts("节点为空");
        return;
    }
    ptr->data[ptr->tail] = new_node;
    ptr->tail = (ptr->tail + 1) % CAPACITY;
    ptr->size++;
}

Node* de_queue(Queue* ptr) {
    if (ptr->size == 0) {
        puts("队列已空");
        return NULL;
    }
    Node* t = ptr->data[ptr->head];
    ptr->head = (ptr->head + 1) % CAPACITY;
    ptr->size--;
    return t;
}

void level_order(Node* root) {
    if (root == NULL) {
        puts("树为空");
        return;
    }
    Queue test;
    Queue* ptr = &test;
    create_queue(ptr);
    en_queue(ptr, root);
    while (ptr->size != 0) {
        Node* t = de_queue(ptr);
        printf("%c ", t->data);
        if (t->lchild != NULL) {
            en_queue(ptr, t->lchild);
        }
        if (t->rchild != NULL) {
            en_queue(ptr, t->rchild);
        }
    }
}
