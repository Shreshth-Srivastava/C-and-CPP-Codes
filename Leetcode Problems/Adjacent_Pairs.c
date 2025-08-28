#include<stdio.h>
#include<stdlib.h>

int Check(int *arr,int target,int index){
    for(int i = 0;i < index;i++){
        if(*(arr + i) == target) return 1;
    }
    return -1;
}

int* restoreArray(int** adjacentPairs, int adjacentPairsSize, int* adjacentPairsColSize, int* returnSize) {
    *returnSize = adjacentPairsSize + 1;
    int index=1,*arr;
    arr = (int *)malloc(sizeof(int)*(*returnSize));
    *(arr) = *((int *)adjacentPairs);
    for(int i = 0;i < adjacentPairsSize;i++){
        for(int j = 0;j < *adjacentPairsColSize;j++){
            if( Check(arr, *((int *)adjacentPairs + i*(*adjacentPairsColSize) + j),index) == -1 ){
                *(arr + index) = *((int *)adjacentPairs + i*(*adjacentPairsColSize) + j);
                index++;
            }
        }
    }
    return arr;
}

int main(void){
    int arr[3][2] = {{2,1},{3,4},{3,2}};
    int *p,a,b;
    a = 2;
    p = restoreArray((int **)arr, 3,&a, &b);
    for(int i=0;i<4;i++) printf("\n%d",p[i]);
    return 0;
}