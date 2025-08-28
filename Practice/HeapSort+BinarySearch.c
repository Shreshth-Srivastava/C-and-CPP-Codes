#include<stdio.h>
#include<stdlib.h>

void swap(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int *arr,int arrSize,int i){
    int largest = i,left = (2*i)+1,right = (2*i)+2;
    if(arr[left] > arr[largest] && left < arrSize) largest = left;
    if(arr[right] > arr[largest] && right < arrSize) largest = right;
    if(largest != i){
        swap(arr,i,largest);
        heapify(arr,arrSize,largest);
    }
}

void HeapSort(int *arr,int arrSize){
    for(int i = (arrSize-1)/2;i>=0;i--) heapify(arr,arrSize,i);
    for(int i = arrSize-1;i>=0;i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
}

int BinarySearch(int *arr,int arrSize,int target){
    int s = 0,e = arrSize-1;
    while(s<=e){
        int m = s + (e - s)/2;
        if(arr[m] == target) return m;
        else{
            if(arr[m] > target) e = m-1;
            else s = m+1;
        }
    }
    return -1;
}

int main(void){
    int a;
    int arr[10] = {1,2,4,3,6,5,7,8,10,9};
    HeapSort(arr,10);
    printf("\nSorted Array:-");
    for(int i = 0;i<10;i++) printf("\n%d",arr[i]);
    printf("\nEnter the element that you want to find: ");
    scanf("%d",&a);
    printf("\nThe element is found at index: %d",BinarySearch(arr,10,a));
    return 0;
}