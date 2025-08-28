#include<stdio.h>

void SelectionSort(int *arr,int N){
    int min;
    for(int i=0;i<N;i++){
        min = i;
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[min]) min = j;
            else continue;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(void){
    int arr[5] = {5,4,3,2,1}, N=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,N);
    for(int i=0;i<N;i++) printf("\n%d",arr[i]);
    return 0;
}