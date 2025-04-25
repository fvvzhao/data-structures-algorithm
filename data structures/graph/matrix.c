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

typedef struct Graph {
    char vertex[CAPACITY];
    int edge[CAPACITY][CAPACITY];
    int vertex_num;
    int edge_num; 
} Graph;

Queue* create_queue();
void en_queue(Queue* q, int value);
int de_queue(Queue* q);
Graph* create_graph(int vertex_num, int edge_num);
void bfs(Graph* graph, int start);
void dfs(Graph* graph, int start, bool visited[]);

int main(void) {

    Graph* graph = create_graph(4, 3);
    for (int i = 0; i < graph->vertex_num; i++)
    {
        graph->vertex[i] = 65 + i;
    }
    puts("请给出邻接矩阵：");
    for (int i = 0; i < graph->vertex_num; i++)
    {
        for (int j = 0; j < graph->vertex_num; j++)
        {
            scanf("%d", &graph->edge[i][j]);
        }
    }
    puts("邻接矩阵的内容：");
    for (int i = 0; i < graph->vertex_num; i++)
    {
        for (int j = 0; j < graph->vertex_num; j++)
        {
            printf("%d ", graph->edge[i][j]);
        }
        printf("\n");
    }

    puts("bfs遍历结果：");
    bfs(graph, 0);
    printf("\n");

    bool visited[CAPACITY] = {false};
    puts("dfs遍历结果：");
    dfs(graph, 0, visited);
    
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
    for (int i = 0; i < CAPACITY; i++)
    {
        for (int j = 0; j < CAPACITY; j++)
        {
            ptr->edge[i][j] = 0;
        }
    }
    return ptr;
}

void bfs(Graph* graph, int start) {
    Queue* q = create_queue();
    en_queue(q, start);
    bool visited[CAPACITY] = {false};
    visited[start] = true;
    while (q->size != 0) {
        int index = de_queue(q);
        printf("%c ", graph->vertex[index]);
        for (int i = 0; i < graph->vertex_num; i++)
        {
            if (graph->edge[index][i] == 1 && visited[i] == false) {
                visited[i] = true;
                en_queue(q, i);
            }
        }
    }
}

void dfs(Graph* graph, int start, bool visited[]) {
    visited[start] = true;
    printf("%c ", graph->vertex[start]);
    for (int i = 0; i < graph->vertex_num; i++)
    {
        if (graph->edge[start][i] == 1 && visited[i] == false) {
            dfs(graph, i, visited);
        }
    }
}
