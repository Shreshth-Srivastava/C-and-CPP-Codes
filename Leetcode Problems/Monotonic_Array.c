#include<stdio.h>
#include<stdbool.h>
bool isMonotonic(int* nums, int numsSize){
    int flag = 0;
    if(nums[0]<nums[numsSize-1]){flag = 1;}
    else{flag = 0;}
    if(flag == 1){for(int i=0;i<numsSize-1;i++){if(nums[i]>nums[i+1]){return false;}}}
    else{for(int j=0;j<numsSize-1;j++){if(nums[j]<nums[j+1]) {return false;}}}
    return true;
}