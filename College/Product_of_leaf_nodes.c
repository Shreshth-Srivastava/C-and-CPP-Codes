#include<stdio.h>

///Assuming that the binary tree is given as an array for input
void LeafNodesProduct(int *arr,int arrsize){
    int result = arr[0];
    for(int i=1;i<=(arrsize-1)/2;i++) result *= arr[i];
    printf("\nProduct of all leaf node = %d",result);
}

int main(void){
    int arr[5] = {1,2,3,4,5};
    LeafNodesProduct(arr,5);
    return 0;
}