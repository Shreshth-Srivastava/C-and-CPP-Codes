#include<stdio.h>
void sort(int array[] , int array_length);
int ceiling(int array[] , int target , int array_lenth);
int floornum(int array[] , int target , int array_lenth);
void main(void){
    int a[] = {2,3,5,9,14,16,18};
    int l=(sizeof(a)/sizeof(int));
    sort(a,l);
    printf("\nceiling  : %d",ceiling(a,19,l));
    printf("\nfloor : %d",floornum(a,19,l));
}
void sort(int array[] , int array_length){
    for(int i=0;i<array_length-1;i++){
        for(int j=i+1;j>0;j--){
            if(array[j]<array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
            else break;
        }
    }
}
int ceiling(int array[] ,int target , int array_length){
    int start = 0;
    int end = array_length-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(array[mid] == target) return array[mid];
        else if(array[mid] > target) end = mid-1;
        else start = mid + 1;
    }
    if(start == array_length) return array[0];
    return array[start];
}
int floornum(int array[] ,int target , int array_length){
    int start = 0;
    int end = array_length-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(array[mid] == target) return array[mid];
        else if(array[mid] > target) end = mid-1;
        else start = mid + 1;
    }
    return array[end];
}