#include<stdio.h>
void cyclesort(int array[] , int array_length);
void swap(int array[] , int a , int b);
int findDuplicate(int* nums, int numsSize);
void main(void){
    int a[]={1,3,4,2,2};
    cyclesort(a,5);
    int ans=findDuplicate(a,5);
    printf("%d",ans);
}
int findDuplicate(int* nums, int numsSize){
    cyclesort(nums,numsSize);
    for(int j=0;j<numsSize;j++){
        if(nums[j]-1 != j) return nums[j];
    }
    return -1;
}
void cyclesort(int array[] , int array_length){
    int i=0;
    while(i<array_length){
        int correct=array[i]-1;
        if(array[i] != array[correct]) swap(array,i,correct);
        else i++;
    }
}
void swap(int array[] , int a , int b){
    int temp = array[a];
    array[a]=array[b];
    array[b]=temp;
}