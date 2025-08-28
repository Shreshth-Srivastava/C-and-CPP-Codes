#include<stdio.h>

void UpperTriangularMatrix(int **arr,int matSize,int matColSize){
    for(int i=1;i<matSize;i++){
        for(int j=0;j<i;j++){
            if((*((int *)arr+3*i+j)) != 0){
                printf("\nNot Upper Triangular Matrix");
                return;
            }
        }
    }
    printf("\nUpper Triangular Matrix");
}

int main(void){
    int arr[3][3] = {
        {1,2,3},
        {0,4,5},
        {0,0,6}
    };
    int *a,**b;
    a = (int *)arr;
    b = (int **)a;
    UpperTriangularMatrix(b,3,3);
    return 0;
}