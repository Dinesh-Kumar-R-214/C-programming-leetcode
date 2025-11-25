#include <stdlib.h>

int findFirst(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int index = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            index = mid;
            right = mid - 1;  // search left half for first occurrence
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return index;
}

int findLast(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int index = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            index = mid;
            left = mid + 1;  // search right half for last occurrence
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return index;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = findFirst(nums, numsSize, target);
    res[1] = findLast(nums, numsSize, target);
    *returnSize = 2;
    return res;
}
