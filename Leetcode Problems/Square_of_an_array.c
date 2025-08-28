#include<stdio.h>
#include<stdlib.h>

void QuickSort(int* nums, int low, int high){
    if(low >= high) return;
    short int s = low, e = high, mid = s+(e-s)/2;
    int pivot = nums[mid];
    while(s<=e){
        while(nums[s]<pivot) s++;
        while(nums[e]>pivot) e--;
        if(s<=e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
    QuickSort(nums,low,e);
    QuickSort(nums,s,high);
}
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i=0;i<numsSize;i++) arr[i] = (nums[i])*(nums[i]);
    QuickSort(arr,0,numsSize-1);
    return arr;
}

int main(void){
    int nums[5] = {-1,0,2,3,4};
    int a;
    int *p = sortedSquares(nums, 5,&a);
    for(int i=0;i<5;i++) printf("\n%d",nums[i]);
    return 0;
}