#include<stdio.h>

void ShellSort(int *arr,int size){
    for(int gap = size/2;gap > 0;gap /=2){
        for(int i = gap;i < size;i++){
            int temp = arr[i];
            int j;
            for(j = i;j >= gap && arr[j-gap] > temp;j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main(void){
    int arr[5] = {12,34,54,2,3};
    int N = sizeof(arr)/sizeof(arr[0]);
    ShellSort(arr,N);
    for(int i = 0;i<N;i++) printf("\n%d",arr[i]);
    return 0;
}