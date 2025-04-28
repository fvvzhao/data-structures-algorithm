#include <stdio.h>

int binary_search(int nums[], int size, int target);

int main(void) {

    int nums[] = {6, 7, 8, 9, 10};
    int size = sizeof(nums) / sizeof(int);
    printf("%d", binary_search(nums, size, 10));

    return 0;
}

int binary_search(int nums[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
