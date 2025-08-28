#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}

int SecondSmallest(int *arr,int N){ //N is the length of the array
    if(N == 0) return 0;
    qsort(arr,N,sizeof(int),cmp);
    return arr[1];
}

int main(void){
    int arr[5] = {1,2,3,4,5}, N = sizeof(arr)/sizeof(arr[0]);
    printf("\n%d",SecondSmallest(arr,N));
    return 0;
}