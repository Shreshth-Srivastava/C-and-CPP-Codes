#include<stdio.h>
#include<stdlib.h>

int minOperations(int* nums, int numsSize) {
    int count = 0, flag = 1;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 0){
            count++;
            for(int j=i;j<=i+2 && (i+2)<numsSize;j++){
                nums[j] = !(nums[j]);
            }
        }
    }
    for(int k=0;k<numsSize;k++){
        if(nums[k] == 0){
            flag = 0;
        }
    }
    if(!flag) return -1;
    else{
        return count;
    }
}

int main(void){
    int arr[4] = {0,1,1,1};
    printf("\n%d", minOperations(arr, 4));
    return 0;
}