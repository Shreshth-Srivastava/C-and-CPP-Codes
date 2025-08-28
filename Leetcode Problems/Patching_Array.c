#include<stdio.h>
#include<stdlib.h>

int minPatches(int* nums, int numsSize, int n) {
    long range = 1, added = 0, i = 0;
    while(range <= n){
        if(i < numsSize && nums[i] <= range){
            range += nums[i++];
        }
        else{
            range += range;
            added++;
        }
    }
    return added;
}

int main(void){
    int nums[] = {1,5,10};
    printf("\nResult: %d", minPatches(nums, 3, 20));
    return 0;
}