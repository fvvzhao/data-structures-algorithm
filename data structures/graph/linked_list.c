#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

typedef struct Queue {
    int data[CAPACITY];
    int size;
    int head;
    int tail;
} Queue;

typedef struct EdgeNode {
    int index;
    struct EdgeNode* next;
} EdgeNode;

typedef struct Vertex {
    char data;
    struct EdgeNode* first;
    struct EdgeNode* tail;
} Vertex;

typedef struct Graph {
    Vertex* vertex[CAPACITY];
    int vertex_num;
    int edge_num;
} Graph;

Queue* create_queue();
void en_queue(Queue* q, int value);
int de_queue(Queue* q);
Graph* create_graph(int vertex_num, int edge_num);
void add_edge(Graph* g, int i_1, int i_2);
void bfs(Graph* g, int start);
void dfs(Graph* g, int start, bool visited[]);

int main(void) {

    Graph* g = create_graph(4, 3);
    add_edge(g, 0, 1);
    add_edge(g, 0, 3);
    add_edge(g, 1, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);
    add_edge(g, 3, 2);

    puts("bfs遍历结果：");
    bfs(g, 0);
    printf("\n");

    bool visited[CAPACITY] = {false};
    puts("dfs遍历结果：");
    dfs(g, 0, visited);

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
    int index = q->data[q->head];
    q->head = (q->head + 1) % CAPACITY;
    q->size--;
    return index;
}

Graph* create_graph(int vertex_num, int edge_num) {
    Graph* ptr = (Graph*)malloc(sizeof(Graph));
    if (ptr == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    ptr->vertex_num = vertex_num;
    ptr->edge_num = edge_num;
    puts("请输入图的顶点：");
    for (int i = 0; i < ptr->vertex_num; i++)
    {
        ptr->vertex[i] = (Vertex*)malloc(sizeof(Vertex));
        if (ptr->vertex[i] == NULL) {
            puts("内存分配失败");
            return NULL;
        }
        char ch;
        scanf(" %c", &ch);
        ptr->vertex[i]->data = ch;
        ptr->vertex[i]->first = NULL;
        ptr->vertex[i]->tail = ptr->vertex[i]->first;
    }
    return ptr;
}

void add_edge(Graph* g, int i_1, int i_2) {
    EdgeNode* new_node = (EdgeNode*)malloc(sizeof(EdgeNode));
    if (new_node == NULL) {
        puts("内存分配失败");
        return;
    }
    new_node->index = i_2;
    new_node->next = NULL;

    if (g->vertex[i_1]->first == NULL) {
        g->vertex[i_1]->first = new_node;
        g->vertex[i_1]->tail = new_node;
    }
    else {
        g->vertex[i_1]->tail->next = new_node;
        g->vertex[i_1]->tail = g->vertex[i_1]->tail->next;
    }
}

void bfs(Graph* g, int start) {
    Queue* q = create_queue();
    en_queue(q, start);
    bool visited[CAPACITY] = {false};
    visited[start] = true;
    while (q->size != 0) {
        int index = de_queue(q);
        printf("%c ", g->vertex[index]->data);
        EdgeNode* t = g->vertex[index]->first;
        while (t != NULL) {
            if (visited[t->index] == false) {
                visited[t->index] = true;
                en_queue(q, t->index);
            }
            t = t->next;
        }
    }
}

void dfs(Graph* g, int start, bool visited[]) {
    visited[start] = true;
    printf("%c ", g->vertex[start]->data);
    EdgeNode* t = g->vertex[start]->first;
    while (t != NULL) {
        if (visited[t->index] == false) {
            dfs(g, t->index, visited);
        }
        t = t->next;
    }
}
