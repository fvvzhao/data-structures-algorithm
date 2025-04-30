#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* lchild;
	struct Node* rchild;
} Node;

typedef struct BST {
	Node* root;
} BST;

BST* create_bst();
Node* create_node(int value);

void insert(BST* bst, int value);

Node* select(Node* root, int value);

void in_order(Node* root);

int main(void)
{
	
	BST* bst = create_bst();
	
	return 0;
}

BST* create_bst()
{
	BST* bst = (BST*)malloc(sizeof(BST));
	if (bst == NULL)
	{
		return NULL;
	}
	bst->root = NULL;
}

Node* create_node(int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->data = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

void insert(BST* bst, int value)
{
	if (bst->root == NULL)
	{	
		Node* new_node = create_node(value);
		bst->root = new_node;
		return;
	}
	Node* t = bst->root;
	Node* parent = NULL;
	while (t != NULL)
	{
		parent = t;
		if (t->data == value)
		{
			return;
		}
		if (t->data > value)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	Node* new_node = create_node(value);
	if (parent->data > value)
	{
		parent->lchild = new_node;
	}
	else
	{
		parent->rchild = new_node;
	}
}

Node* select(Node* root, int value)
{
	if (root == NULL)
	{
		return NULL;
	}
	Node* t = root;
	while (t != NULL)
	{
		if (t->data == value)
		{
			return t;
		}
		if (t->data > value)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	return NULL;
}

void in_order(Node* root)
{
	if (root != NULL)
	{
		in_order(root->lchild);
		printf("%d ", root->data);
		in_order(root->rchild);
	}
}
