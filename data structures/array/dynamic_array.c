#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int* data;
    int size;
    int capacity;
} Array;

Array* create_array(int capacity);
void increase_capacity(Array* array, int increased_size);
void insert(Array* array, int index, int value);
int delete(Array* array, int index);
void update(Array* array, int index, int value);
int select(Array* array, int index);
void print_array(Array* array);


int main(void) {

    Array* array = create_array(10);

    return 0;
}

Array* create_array(int capacity) {
    Array* array = (Array*)malloc(sizeof(Array));
    if (array == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    array->data = (int*)malloc(sizeof(capacity * sizeof(int)));
    if (array->data == NULL) {
        puts("内存分配失败");
        free(array);
        return NULL;
    }
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void increase_capacity(Array* array, int increased_size) {
    int* t = array->data;
    array->data = (int*)malloc((array->capacity + increased_size) * sizeof(int));
    if (array->data == NULL) {
        puts("内存分配失败");
        return;
    }
    array->capacity += increased_size;
    for (int i = 0; i < array->size; i++) {
        array->data[i] = t[i];
    }
    free(t);
}

void insert(Array* array, int index, int value) {
    if (index < 0 || index > array->size || array->size == array->capacity) {
        puts("插入失败");
        return;
    }
    for (int i = array->size - 1; i >= index; i--) {
        array->data[i + 1] = array->data[i];
    }
    array->data[index] = value;
    array->size++;
}

int delete(Array* array, int index) {
    if (index < 0 || index > array->size - 1 || array->size == 0) {
        puts("删除失败");
        return -1;
    }
    int t = array->data[index];
    for (int i = index + 1; i < array->size; i++) {
        array->data[i - 1] = array->data[i];
    }
    array->size--;
    return t;
}

void update(Array* array, int index, int value) {
    if (index < 0 || index > array->size - 1 || array->size == 0) {
        puts("更新失败");
        return;
    }
    array->data[index] = value;
}

int select(Array* array, int index) {
    if (index < 0 || index > array->size - 1 || array->size == 0) {
        puts("查找失败");
        return -1;
    }
    return array->data[index];
}

void print_array(Array* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
}
