#include<stdio.h>
void cyclesort(int array[] , int array_length);
void swap(int array[] , int a , int b);
int missingNumber(int* nums, int numsSize);
void main(void){
    int nums[] = {0,2,4,1};
    int numsSize=(sizeof(nums)/sizeof(int));
    printf("%d",missingNumber(nums,numsSize));
}
int missingNumber(int* nums, int numsSize){
    cyclesort(nums,numsSize);
    for(int j=0;j<numsSize;j++){
        if(nums[j] != j) return j;
    }
    return numsSize;
}
void cyclesort(int array[] , int array_length){
    int i=0;
    while(i<array_length){
        int correct=array[i];
        if(array[i] != array_length && array[i] != array[correct]) swap(array,i,correct);
        else i++;
    }
}
void swap(int array[] , int a , int b){
    int temp = array[a];
    array[a]=array[b];
    array[b]=temp;
}