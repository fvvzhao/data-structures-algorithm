#include <stdio.h>

int linear_search(int nums[], int size, int target);

int main(void) {

    int nums[] = {6, 7, 8, 9, 10};
    int size = sizeof(nums) / sizeof(int);
    printf("%d", linear_search(nums, size, 8));
    
    return 0;
}

int linear_search(int nums[], int size, int target) {
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}
