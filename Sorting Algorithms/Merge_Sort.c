#include<stdio.h>

void Merge(int *arr,int l,int m,int r){
    int i = 0,j = 0,k = l,n1 = m-l+1,n2 = r-m,arr1[n1],arr2[n2];
    for(i;i<n1;i++) arr1[i] = arr[l+i];
    for(j;j<n2;j++) arr2[j] = arr[m+1+j];
    i = 0;j = 0;
    while(i<n1 && j<n2){
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
    while(i<n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr,int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}

int main(void){
    int arr[6] = {12,11,13,5,6,7};
    MergeSort(arr,0,5);
    for(int i=0;i<6;i++) printf("\n%d",arr[i]);
    return 0;
}