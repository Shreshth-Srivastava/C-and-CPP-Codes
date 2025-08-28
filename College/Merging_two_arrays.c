#include<stdio.h>
#include<stdlib.h>

int *Merge(int *arr1,int *arr2,int size1,int size2){
    int i = 0,j = 0,k = 0;
    int *arr = (int *)malloc(sizeof(int)*(size1+size2));
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i<size1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return arr;
}

int main(void){
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,4,6,8,10};
    int *c = Merge(a,b,5,5);
    for(int k=0;k<10;k++) printf("\n%d",c[k]);
    return 0;
}