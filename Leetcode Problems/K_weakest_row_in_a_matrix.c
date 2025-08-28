#include<stdio.h>
#include<stdlib.h>

int CheckIndex(int *arr, int N, short int target){
    if(arr[0] == -1) return 1;
    else{
        for(short int i=0;i<N;i++){
            if(arr[i] == target) return 0;
        }
    }
    return 1;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    short int a=0,b=matSize-1;
    int *arr;
    if(matSize > 0){
        arr = (int *)malloc(sizeof(int)*matSize);
        arr[0] = -1;
    }
    else return NULL;
    for(int j=0;j<*matColSize;j++){
        for(int i=0;i<matSize;i++){
            if(*((int *)mat + i*(*matColSize) + j) == 0 && CheckIndex(arr,matSize,i)) arr[a++] = i;
        }
    }
    for(int j=*matColSize-1;j>=0;j--){
        for(int i=matSize-1;i>=0;i--){
            if(*((int *)mat + i*(*matColSize) + j) == 1 && CheckIndex(arr,matSize,i)) arr[b--] = i;
        }
    }
    if(arr[0] == -1) arr[0] = 0;
    *returnSize = k;
    return arr;
}

int main(void){
    int mat[5][5] = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int  *b,*c;
    c = kWeakestRows((int **)mat,5,(int *)5,3,b);
    for(int i=0;i<3;i++) printf("\n%d",c[i]);
    return 0;
}