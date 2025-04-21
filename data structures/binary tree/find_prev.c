#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

Node* pre = NULL;
Node* final = NULL;

void create_binary_tree(BinaryTree* ptr, char value);
Node* create_node(char value);
void visit(Node* ptr, Node* target);
void pre_order(Node* root, Node* target);
void in_order(Node* root, Node* target);
void post_order(Node* root, Node* target);

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

    // B
    Node* target = ptr->root->lchild;
    pre = NULL;
    final = NULL;
    pre_order(ptr->root, target);
    printf("%c\n", final->data);

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

void visit(Node* ptr, Node* target) {
    if (ptr == target) {
        final = pre;
    }
    else {
        pre = ptr;
    }
}

void pre_order(Node* root, Node* target) {
    if (root != NULL) {
        visit(root, target);
        pre_order(root->lchild, target);
        pre_order(root->rchild, target);
    }
}

void in_order(Node* root, Node* target) {
    if (root != NULL) {
        in_order(root->lchild, target);
        visit(root, target);
        in_order(root->rchild, target);
    }
}

void post_order(Node* root, Node* target) {
    if (root != NULL) {
        post_order(root->lchild, target);
        post_order(root->rchild, target);
        visit(root, target);
    }
}
