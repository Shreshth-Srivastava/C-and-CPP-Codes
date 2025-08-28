#include<stdio.h>

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

int main(void){
    int arr[6] = {13,-1,0,20,100,9999};
    InsertionSort(arr,6);
    for(int i=0;i<6;i++) printf("\n%d",arr[i]);
    return 0;
}