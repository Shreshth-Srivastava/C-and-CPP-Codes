#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr,int N,int i){
    int largest = i,left = 2*i+1,right = 2*i+2;
    if(left < N && arr[largest] < arr[left]) largest = left;
    if(right < N && arr[largest] < arr[right]) largest = right;
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,N,largest);
    }
}

void HeapSort(int* arr,int N){
    for(int i=(N-1)/2;i>=0;i--){
        heapify(arr,N,i);
    }
    for(int i=N-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(void){
    int arr[5] = {-1,-2,0,22,99};
    HeapSort(arr,5);
    for(int i=0;i<5;i++) printf("\n%d",arr[i]);
    return 0;
}