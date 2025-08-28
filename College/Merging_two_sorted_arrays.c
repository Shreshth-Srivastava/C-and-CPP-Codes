#include<stdio.h>
#include<stdlib.h>

int *Merge(int *arr1,int size1,int *arr2,int size2){
    int *arr = (int *)malloc(sizeof(int) * (size1+size2));
    int i = 0,j = 0,k = 0;
    while(i < size1 && j < size2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return arr;
}

int main(void){
    int arr1[5] = {6,7,8,9,10}, arr2[5] = {1,2,3,4,5};
    int *arr;
    arr = Merge(arr1,5,arr2,5);
    for(int i=0;i<10;i++) printf("\n%d",arr[i]);
    return 0;
}