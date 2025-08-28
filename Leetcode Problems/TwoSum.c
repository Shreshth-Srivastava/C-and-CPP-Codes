#include<stdio.h>
#include<malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(void){
    int a[5] = {1,2,3,4,5};
    int *p, *returnSize;
    p = twoSum(a,5,9,returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("\n%d",*(p+i));
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if ((*(nums+i) + *(nums+j)) == target){
                *a = i,*(a + 1) = j;
                return a;
            }
        }
    }
    *a = -1,*(a + 1) = -1;
    return a;
}