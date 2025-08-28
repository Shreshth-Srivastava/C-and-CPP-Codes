#include<stdio.h>

void SumRowColumn(int **mat,int matSize,int matColSize){
    int sum;
    for(int i=0;i<matSize;i++){
        sum = *((int *)mat +i*matColSize);
        for(int j=1;j<matColSize;j++){
            sum += *((int *)mat +i*matColSize+j);
        }
        printf("\nSum of elements in row %d : %d",i+1,sum);
    }
    for(int j=0;j<matColSize;j++){
        sum = *((int *)mat +j);
        for(int i=1;i<matSize;i++){
            sum += *((int *)mat +i*matColSize+j);
        }
        printf("\nSum of elements in column %d : %d",j+1,sum);
    }
}

int main(void){
    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    SumRowColumn((int **)mat,3,3);
    return 0;
}