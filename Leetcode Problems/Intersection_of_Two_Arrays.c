#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Better Solution

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int N;
    if(nums1Size < nums2Size) N = nums1Size;
    else N = nums2Size;
    
    int *arr = (int *)malloc(sizeof(int) * N),arrSize = 0;

    bool check[1001] = {false};
    
    for(int i = 0;i < nums1Size;i++){
        if(!check[nums1[i]]) check[nums1[i]] = true;
    }
    for(int j = 0;j < nums2Size;j++){
        int num = nums2[j];
        if(check[num]){
            check[nums2[j]] = false;
            arr[arrSize] = num;
            arrSize++;
        }
    }

    *returnSize = arrSize;
    return arr;
}

//My Solution

/*int BinarySearch(int *arr,int target,int Size){
    int s = 0,e = Size-1;
    while(s<=e){
        int m = s+(e-s)/2;
        if(arr[m] == target) return 1;
        else if(arr[m] > target) e = m-1;
        else s = m+1;
    }
    return 0;
}

int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int N;
    if(nums1Size < nums2Size) N = nums1Size;
    else N = nums2Size;
    
    int *arr = (int *)malloc(sizeof(int) * N);
    int a[nums1Size],b[nums2Size],c = 1,d = 1,arrSize = 0;
    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size,sizeof(int),cmp);

    a[0] = nums1[0];
    b[0] = nums2[0];

    for(int i = 1;i<nums1Size;i++){
        if(nums1[i] != nums1[i-1]){
            a[c] = nums1[i];
            c++;
        }
    }
    for(int i = 1;i<nums2Size;i++){
        if(nums2[i] != nums2[i-1]){
            b[d] = nums2[i];
            d++;
        }
    }

    for(int i = 0;i < c;i++){
        if(BinarySearch(b,a[i],d)){
            arr[arrSize] = a[i];
            arrSize++;
        }
    }

    *returnSize = arrSize;
    return arr;
}*/

int main(void){
    return 0;
}