#include<stdio.h>
#include<stdlib.h>
void swap(int* nums, int a, int b);
int* findDuplicates(int* nums, int numsSize, int* returnSize);
int main(void){
    int array[]={4,3,2,7,8,2,3,1};
    int* returnSize;
    int* arr;
    arr = findDuplicates(array, 8, returnSize);
    printf("------------------------------------------\n");
    for(int n=0;n<*returnSize;n++) printf("%d\n",arr[n]);
    return 0;
}
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int i=0,j=0;
    while(i<numsSize){
        int correct = nums[i] - 1;
        if(nums[i] != nums[correct]) swap(nums, i, correct);
        else i++;
    }
    for(int m=0;m<numsSize;m++) printf("%d\n",nums[m]);
    for(int k=0;k<numsSize;k++) if(nums[k] != k+1) j++;
    int *a = (int *)malloc(sizeof(int)*j);
    *returnSize = j;
    for(int l=0;l<numsSize;l++) if(nums[l] != l+1){ 
        if(j>0){
            a[j-1] = nums[l];
            j--;
        }
    }
    return a;
}
void swap(int* nums, int a, int b){
    int swap = nums[a];
    nums[a] = nums[b];
    nums[b] = swap;
}