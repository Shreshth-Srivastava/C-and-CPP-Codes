#include<stdio.h>
#include<math.h>

int BinaryTreeHeight(int num){  ///num denotes the number of nodes in the binary tree
    return log2(num);
}

int main(void){
    int a;
    printf("\nEnter the no. of elements: ");
    scanf("%d",&a);
    printf("\nHeight of binary tree = %d",BinaryTreeHeight(a)+1);
    return 0;
}