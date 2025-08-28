#include<stdio.h>
#include<stdlib.h>

int minOperations(int* nums, int numsSize) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 0){
            count++;
            for(int j=i;j<numsSize;j++){
                nums[j] = !(nums[j]);
            }
        }
    }
    return count;
}

int main(void){
    int arr[4] = {1,0,0,0};
    printf("\n%d", minOperations(arr, 4));
    return 0;
}