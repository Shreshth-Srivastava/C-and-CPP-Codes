#include<stdio.h>

void MaxInRow(int **mat,int matSize,int matColSize){
    if(matSize != 0){
        int max;
        for(int i=0;i<matSize;i++){
            max = *((int *)mat + i*matColSize);
            for(int j=0;j<matColSize;j++){
                if(*((int *)mat + i*matColSize + j) > max) max = *((int *)mat + i*matColSize + j);
            }
            printf("\nMax in row %d : %d",i+1,max);
        }
    }
}

int main(void){
    int arr[3][3] = {
        {1,2,3},
        {6,5,4},
        {8,9,7}
    };
    MaxInRow((int **)arr,3,3);
    return 0;
}