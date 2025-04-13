#include <stdio.h>

#define CAPACITY 10

typedef struct StaticArray {
    int data[CAPACITY];
    int size;
} StaticArray;

void create(StaticArray* ptr);
void insert(StaticArray* ptr, int index, int value);
void delete(StaticArray* ptr, int index);
void update(StaticArray* ptr, int index, int value);
void select(StaticArray* ptr, int index);
void print_array(StaticArray* ptr);

int main(void) {

    StaticArray test;
    StaticArray* ptr = &test;
    create(ptr);

    insert(ptr, 0, 1);
    insert(ptr, 1, 2);
    insert(ptr, 2, 3);
    print_array(ptr);

    return 0;
}

// 创
void create(StaticArray* ptr) {
    ptr->size = 0;
}

// 增
void insert(StaticArray* ptr, int index, int value) {
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
void delete(StaticArray* ptr, int index) {
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
void update(StaticArray* ptr, int index, int value) {
    if (index < 0 || index > ptr->size - 1 || ptr->size == 0) {
        puts("更新失败");
        return;
    }
    ptr->data[index] = value;
}

// 查
void select(StaticArray* ptr, int index) {
    if (index < 0 || index > ptr->size - 1 || ptr->size == 0) {
        puts("查找失败");
        return;
    }
    printf("您所查找的索引为 %d 的元素的数值为：%d\n", index, ptr->data[index]);
}

// 遍历
void print_array(StaticArray* ptr) {
    for (int i = 0; i < ptr->size; i++) {
        printf("%d ", ptr->data[i]);
    }
    printf("\n");
}
