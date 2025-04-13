#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct DynamicArray {
    int* data;
    int size;
    int capacity;
} DynamicArray;

void create(DynamicArray* ptr);
void insert(DynamicArray* ptr, int index, int value);
void delete(DynamicArray* ptr, int index);
void update(DynamicArray* ptr, int index, int value);
void select(DynamicArray* ptr, int index);
void print_array(DynamicArray* ptr);
void increase_capacity(DynamicArray* ptr, int increased_size);

int main(void) {

    DynamicArray test;
    DynamicArray* ptr = &test;
    create(ptr);

    insert(ptr, 0, 1);
    insert(ptr, 1, 2);
    insert(ptr, 2, 3);
    print_array(ptr);

    return 0;
}

// 创
void create(DynamicArray* ptr) {
    ptr->data = (int*)malloc(sizeof(int) * CAPACITY);
    if (ptr->data == NULL) {
        puts("内存分配失败");
        return;
    }
    ptr->size = 0;
    ptr->capacity = CAPACITY;
}

// 增
void insert(DynamicArray* ptr, int index, int value) {
    if (index < 0 || index > ptr->size || ptr->size == CAPACITY) {
        puts("插入失败");
        return;
    }
    for (int i = ptr->size - 1; i >= index; i--) {
        ptr->data[i + 1] = ptr->data[i];
    }
    ptr->data[index] = value;
    ptr->size++;
}

// 删
void delete(DynamicArray* ptr, int index) {
    if (index < 0 || index > ptr->size - 1 || ptr->size == 0) {
        puts("删除失败");
        return;
    }
    for (int i = index + 1; i < ptr->size; i++) {
        ptr->data[i - 1] = ptr->data[i];
    }
    ptr->size--;
}

// 改
void update(DynamicArray* ptr, int index, int value) {
    if (index < 0 || index > ptr->size - 1 || ptr->size == 0) {
        puts("更新失败");
        return;
    }
    ptr->data[index] = value;
}

// 查
void select(DynamicArray* ptr, int index) {
    if (index < 0 || index > ptr->size - 1 || ptr->size == 0) {
        puts("查找失败");
        return;
    }
    printf("您所查找的索引为 %d 的元素的数值为：%d\n", index, ptr->data[index]);
}

// 遍历
void print_array(DynamicArray* ptr) {
    for (int i = 0; i < ptr->size; i++) {
        printf("%d ", ptr->data[i]);
    }
    printf("\n");
}

// 扩容
void increase_capacity(DynamicArray* ptr, int increased_size) {
    int* temp = ptr->data;
    ptr->data = (int*)malloc(sizeof(int) * (ptr->capacity + increased_size));
    if (ptr->data == NULL) {
        puts("内存分配失败");
        return;
    }
    ptr->capacity += increased_size;
    for (int i = 0; i < ptr->size; i++) {
        ptr->data[i] = temp[i];
    }
    free(temp);
    printf("增加后的动态数组容量为：%d\n", ptr->capacity);
}
