#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
    int ltag;
    int rtag;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

Node* pre = NULL;

void create_binary_tree(BinaryTree* ptr, char value);
Node* create_node(char value);
void visit(Node* ptr);
void pre_order(Node* root);
void create_pre_thread(Node* root);
void in_order(Node* root);
void create_in_thread(Node* root);
void post_order(Node* root);
void create_post_thread(Node* root);

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
    ptr->root->ltag = 0;
    ptr->root->rtag = 0;
    ptr->root->lchild->ltag = 0;
    ptr->root->lchild->rtag = 0;
    ptr->root->rchild->ltag = 0;
    ptr->root->rchild->rtag = 0;

    pre = NULL;
    create_post_thread(ptr->root);
    
    // E
    Node* E = ptr->root->lchild->rchild;
    printf("%c", E->rchild->data);

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

void visit(Node* ptr) {
    if (ptr->lchild == NULL) {
        ptr->lchild = pre;
        ptr->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = ptr;
        pre->rtag = 1;
    }
    pre = ptr;
}

void pre_order(Node* root) {
    if (root != NULL) {
        visit(root);
        if (root->ltag == 0) {
            pre_order(root->lchild);
        }
        pre_order(root->rchild);
    }
}

void create_pre_thread(Node* root) {
    if (root != NULL) {
        pre_order(root);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

void in_order(Node* root) {
    if (root != NULL) {
        in_order(root->lchild);
        visit(root);
        in_order(root->rchild);
    }
}

void create_in_thread(Node* root) {
    if (root != NULL) {
        in_order(root);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

void post_order(Node* root) {
    if (root != NULL) {
        post_order(root->lchild);
        post_order(root->rchild);
        visit(root);
    }
}

void create_post_thread(Node* root) {
    if (root != NULL) {
        post_order(root);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}
