#include<stdio.h>

void MaxInColumn(int **mat,int matSize,int matColSize){
    if(matSize != 0){
        int max;
        for(int j=0;j<matColSize;j++){
            max = *((int *)mat + j);
            for(int i=0;i<matSize;i++){
                if(*((int *)mat + i*matColSize + j) > max) max = *((int *)mat + i*matColSize + j);
            }
            printf("\nMax in column %d : %d",j+1,max);
        }
    }
}

int main(void){
    int arr[3][3] = {
        {1,2,7},
        {6,9,4},
        {8,5,3}
    };
    MaxInColumn((int **)arr,3,3);
    return 0;
}