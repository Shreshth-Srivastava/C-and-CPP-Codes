#include<stdio.h>

int Largest(int *arr,int N){ //N is the size of the array
    int max = arr[0];
    for(int i=0;i<N;i++){
        if(arr[i]>max) max = arr[i];
    }
    return max;
}

int Smallest(int *arr,int N){ //N is the size of the array
    int min = arr[0];
    for(int i=0;i<N;i++){
        if(arr[i]<min) min = arr[i];
    }
    return min;
}

int main(void){
    int arr[5] = {5,4,3,2,1}, N = sizeof(arr)/sizeof(arr[0]);
    printf("\nSmallest in array = %d",Smallest(arr,N));
    printf("\nLargest in array = %d",Largest(arr,N));
    return 0;
}