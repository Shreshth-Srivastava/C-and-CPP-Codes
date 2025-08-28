#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int N, int i){ //N is the size of the array
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < N && arr[left] > arr[largest]) largest = left;
    if(right < N && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,N,largest);
    }
}

void HeapSort(int* arr, int N){ //N is the size of the array
    for(int i = N/2 - 1;i>=0;i--){
        heapify(arr,N,i);
    }
    for(int i = N-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(void){
    int arr[6] = {12,11,13,5,6,7};
    HeapSort(arr,6);
    for(int i=0;i<6;i++) printf("\n%d",arr[i]);
    return 0;
}