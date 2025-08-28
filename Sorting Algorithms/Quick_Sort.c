#include<stdio.h>

void QuickSort(int *nums, int low, int high){
    if(low >= high) return;
    int s = low;
    int e = high;
    int m = s + (e-s)/2;
    int pivot = nums[m];
    while(s <= e){
        //also a reason why if its already sorted it will not swap
        while(nums[s]<pivot) s++;
        while(nums[e]>pivot) e--;
        if(s <= e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
    //now pivot is at correct index, now sort the two halves
    QuickSort(nums,low,e);
    QuickSort(nums,s,high);
}

int main(void){
    int arr[5] = {5,4,3,2,1};
    QuickSort(arr,0,4);
    for(int i = 0;i<5;i++) printf("\n%d",arr[i]);
    return 0;
}