#include<stdio.h>

void swap(int *arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void InsertionSort(int *arr, int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
}

void QuickSort(int *arr,int l,int h){
    int s = l,e = h,m = s+(e-s)/2,pivot = arr[m];
    if(l>=h) return;
    else{
        while(arr[s] < pivot) s++;
        while(arr[e] > pivot) e--;
        if(s <= e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    QuickSort(arr,l,e);
    QuickSort(arr,s,h);
}

void heapify(int *arr,int N,int i){
    int largest = i,left = 2*i+1,right = 2*i+2;
    if(left < N && arr[left] > arr[largest]) largest = left;
    if(right < N && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(arr,i,largest);
        heapify(arr,i,largest);  // !Important Step
    }
}

void HeapSort(int *arr,int N){
    for(int i = N/2 - 1;i>=0;i--){
        heapify(arr,N,i);
    }
    for(int i = N-1;i>=0;i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
}

int main(void){
    int arr[6] = {13,-1,0,20,100,9999};
    HeapSort(arr,6);
    for(int i=0;i<6;i++) printf("\n%d",arr[i]);
    return 0;
}