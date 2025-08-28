#include<stdio.h>
#include<stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2*numsSize;
    int *arr = (int *)malloc(sizeof(int)*(*returnSize));
    for(int i = 0;i<numsSize;i++){
        arr[i] = nums[i];
        arr[i+numsSize] = nums[i];
    }
    return arr;
}
