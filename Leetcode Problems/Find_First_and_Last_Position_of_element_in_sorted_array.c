#include<stdio.h>
#include<stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int start = 0 , end = numsSize - 1 , min = -1 , max = -1;
    if(numsSize == 1){
        if(nums[start] == target){
            max = start;
            min = max;
        }
    }
    if(numsSize > 1){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target){
                min = mid;
                max = mid;
                for(int i = mid;i>=0;i--){
                    if(nums[i] != target){
                        min = i+1;
                        break;
                    }
                    else{
                        min = i;
                        continue;
                    }
                    
                }
                for(int j = mid;j<numsSize;j++){
                    if(nums[j] != target){
                        max = j-1;
                        break;
                    }
                    else{
                        max = j;
                        continue;
                    }
                }
                start = end+1;
            }
            else{
                if(nums[mid]>target) end = mid - 1;
                else start = mid+1;
            }
        }
    }
    *returnSize = 2;
    int *arr = (int*)malloc(2*sizeof(int));
    arr[0] = min;
    arr[1] = max;
    return arr;
}

int main(void){
    int nums[1] = {1};
    int returnSize;
    int *p;
    p = searchRange(nums,1,1,&returnSize);
    for(int i=0;i<returnSize;i++) printf("\n%d",p[i]);
    return 0;
}