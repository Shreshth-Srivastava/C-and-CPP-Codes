#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}

void repeatingElements(int *arr,int arrLength){
    qsort(arr,arrLength,sizeof(int),cmp);
    int count = 1;
    for(int i=0;i<arrLength-1;i++){
        if(arr[i] != arr[i+1] && count > 1){
            printf("\n%d is repeated %d times",arr[i],count);
            count = 1;    
        }
        if(arr[i] == arr[i+1]) count++;
    }
}

int main(void){
    int arr[10] = {5,2,4,4,6,5,4,2,2,1};
    repeatingElements(arr,10);
    return 0;
}