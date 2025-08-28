#include<stdio.h>
#include<stdbool.h>

int Check(int *seen,int data,int n){
    for(int i = 0;i<n;i++) if(seen[i] == data) return 1;
    return 0;
}

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    int i = 0,j = 0,count = 0,end = 0,seen[n];
    if(n<3) return false;
    else{
        while(i<n){
            // if(*(leftChild+i) == -1 && *(rightChild+j) != -1) return false;
            if(*(leftChild+i) != -1){
                count++;
                if(!Check(seen,*(leftChild+i),n)){
                    seen[j] = *(leftChild+i);
                    j++;
                    }
                else return false;
            }
            if(*(rightChild+i) != -1){
                count++;
                if(!Check(seen,*(rightChild+i),n)){
                    seen[j] = *(rightChild+i);
                    j++;
                    }
                else return false;
            }
            if(*(leftChild+i) == -1 || *(rightChild+i) == -1) end++;
            i++;
        }
        if(end == 2*count) return false;
    }
    return true;
}

int main(void){
    int leftChild[4] = {1,-1,3,-1};
    int rightChild[4] = {2,-1,-1,-1};
    printf("\n%d",validateBinaryTreeNodes(4,leftChild,4,rightChild,4));
    return 0;
}