#include<stdio.h>
#include<stdlib.h>

int minimumOperations(int* nums, int numsSize) {
    int count = 0, temp;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%3){
            count++; 
            }
        }
    return count;
}

int main(void){
    int arr[3] = {1,2,4};
    printf("\n%d",minimumOperations(arr, 3));
    return 0;
}