#include<stdio.h>

int MaxPosition(int *nums,int target,int end){
    int start = 0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid+1;
        else{
            if(nums[mid]>target) end = mid - 1;
            else start =  mid+1;
        }
    }
    return start;
}

// void RemoveElement(int* nums, int index,int* numsSize){
//     for(int k=index;k<*numsSize-1;k++){
//         nums[k] = nums[k+1];
//     }
//     *numsSize = *numsSize - 1;
// }

// void RemoveElement(int* nums, int index,int* numsSize,int *count){
//     int duplicates = 1;
//     for(int i=index;i<*(numsSize)-1;i++){
//         if(nums[i]==nums[i+1]) duplicates++;
//         else break;
//     }
//     for(int j=index;j<*(numsSize)-duplicates;j++){
//         nums[j] = nums[j+duplicates];
//     }
//     *numsSize = *(numsSize) - duplicates;
//     *(count) += duplicates;
// }

int RemoveElement(int *nums,int numsSize){
    int uniqueLen = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i - 1]) nums[uniqueLen++] = nums[i];
    }
    return uniqueLen;
}

// int BinarySearch(int *nums, int numsSize, int target, int start){
//     int end = numsSize - 1;
//     while(start<=end){
//         int mid = start + (end-start)/2;
//         if(nums[mid] == target) return mid;
//         else{
//             if(nums[mid]>target) end = mid - 1;
//             else start =  mid+1;
//         }
//     }
//     return -1;
// }

void QuickSort(int *nums, int low, int high){
    if(low >= high) return;
    int s = low;
    int e = high;
    int m = s + (e-s)/2;
    int pivot = nums[m];
    while(s <= e){
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
    QuickSort(nums,low,e);
    QuickSort(nums,s,high);
}

// void swap(int *nums, int a, int b){
//     int temp = nums[a];
//     nums[a] = nums[b];
//     nums[b] = temp;
// }

// void InsertionSort(int* nums, int numsSize){
//     for(int i = 0;i<numsSize - 1;i++){
//         for(int j=i+1;j>0;j--){
//             if(nums[j]<nums[j-1]) swap(nums,j,j-1);
//             else break;
//         }
//     }
// }

// int minOperations(int* nums,int numsSize){
//     int check = -1, min, max, N = numsSize, count = 0, maxpos = 0, ans = numsSize, flag;
//     if(numsSize == 1) return 0;
//     else{
//         InsertionSort(nums,N);
//         for(int i = 0;i<N-1;i++){
//             flag = 1;
//             while(flag){
//                 check = BinarySearch(nums,N,nums[i],i+1);
//                 if(check != -1){
//                     RemoveElement(nums,i,&N);
//                     count++;
//                 }
//                 else flag = 0;
//             }
//         }
//         for(int l = 0;l<N-1;l++){
//             min = nums[l];
//             max = min + numsSize - 1;
//             maxpos = MaxPosition(nums,max,N-1);
//             count = maxpos - l;
//             if((numsSize - count)<ans) ans = numsSize - count; 
//         }

//     }
//     return ans;
// }

int minOperations(int* nums,int numsSize){
    int min, max, N = numsSize, count = 0, maxpos = 0, ans = numsSize;
    if(numsSize == 1) return 0;
    else{
        // InsertionSort(nums,N);
        QuickSort(nums,0,N-1);
        // for(int i=0;i<N-1;i++){
        //     if(nums[i] == nums[i+1]) RemoveElement(nums,i+1,&N,&count);
        //     else continue;
        // }
        N = RemoveElement(nums,N);
        for(int l = 0;l<N-1;l++){
            min = nums[l];
            max = min + numsSize - 1;
            maxpos = MaxPosition(nums,max,N-1);
            count = maxpos - l;
            if((numsSize - count)<ans) ans = numsSize - count; 
        }

    }
    return ans;
}

int main(void){
    int nums[4] = {4,3,2,5};
    // int nums[16] = {29,32,46,30,11,32,49,26,18,33,34,16,48,42,23,33};
    printf("\n%d",minOperations(nums,4));
    return 0;
}