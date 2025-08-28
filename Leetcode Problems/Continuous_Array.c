#include<stdio.h>

int ContinuousArray(int* nums, int numsSize){
    int min = nums[0], max = nums[0], count = 0, count1 = 0, count2 = 0;
    ///Check for 1st Condition
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i] == nums[j]){
                nums[j] = nums[j]+1;
                count++;
            }
            else continue;
        }
    }
    ///Check for 2nd Condition
    for(int k=0;k<numsSize;k++){
        if(nums[k]>max) max = nums[k];
        else{
            if(nums[k]<min) min = nums[k];
            else continue;
        }
    }
    if(max-min != numsSize-1){
        min = max - numsSize + 1;
        for(int l=0;l<numsSize-1;l++){
            if(nums[l] != min + l) count1++;
            else continue;
        }
        max = min + numsSize - 1;
        for(int m = numsSize-1;m>0;m--){
            if(nums[m] != max-(numsSize-1-m)) count2++;
            else continue;
        }
    }
    if(count1>count2) count = count+count2;
    else count = count+count1;
    return count;
}

int main(void){
    int nums[4] = {1,10,100,1000};
    printf("\n%d",ContinuousArray(nums,4));
    return 0;
}