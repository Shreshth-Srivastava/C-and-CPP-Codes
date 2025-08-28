#include <stdio.h>
int find132Pattern(int *nums, int numsSize){
    int flag = 0;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[j]>nums[i]){
                for(int k=j+1;k<numsSize;k++){
                    if(nums[k]<nums[j] && nums[i]<nums[k]){
                        flag = 1;
                        return flag;
                    }
                    else{
                        if(nums[j] == nums[j+1]) j++;
                        else{
                            if(nums[k]>nums[j]) j=k;
                            else continue;
                        }
                    }
                }
            }
            else{
                if(nums[i] == nums[i+1]) i++;
                else{
                    if(nums[j]<nums[i]) i=j;
                    else continue;
                }
            }
        }
    }
    return flag;
}
int main(void)
{
    int arr[8] = {1, 4, 0, -1, -2, -3, -1, -2};
    int *a = arr;
    int b = find132Pattern(a, 8);
    if (b == 0)
        printf("\nFalse");
    else
        printf("\nTrue");
    return 0;
}