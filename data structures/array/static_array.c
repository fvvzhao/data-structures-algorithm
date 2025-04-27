#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct Array {
    int data[CAPACITY];
    int size;
} Array;

Array* create_array();
void insert(Array* array, int index, int value);
int delete(Array* array, int index);
void update(Array* array, int index, int value);
int select(Array* array, int index);
void print_array(Array* array);

int main(void) {

    Array* array = create_array();

    return 0;
}

Array* create_array() {
    Array* array = (Array*)malloc(sizeof(Array));
    if (array == NULL) {
        puts("内存分配失败");
        return NULL;
    }
    array->size = 0;
    return array;
}

void insert(Array* array, int index, int value) {
    if (index < 0 || index > array->size || array->size == CAPACITY) {
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
