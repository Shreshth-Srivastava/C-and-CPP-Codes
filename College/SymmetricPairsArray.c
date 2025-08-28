#include<stdio.h>

void SymmetricPairs(int *arr,int rows){
    for(int i = 0;i < 2*rows;i += 2){
        for(int j = i+2;j < 2*rows;j +=2){
            if(arr[i] == arr[j+1]){
                if(arr[i+1] == arr[j]){
                    printf("\n(%d,%d)\n",arr[i],arr[i+1]);
                }
            }
        }
    }
}

int main(void){
    int arr[5][2] = {{1,2},{4,3},{5,6},{3,4},{2,1}};
    SymmetricPairs((int *)arr,5);
    return 0;
}