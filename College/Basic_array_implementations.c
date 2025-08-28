#include<stdio.h>
#include<stdlib.h>

void Insertion(int *arr,int *n){
    int val,index;
    printf("\nEnter the element that you want to insert: ");
    scanf("%d",&val);
    printf("\nEnter index: ");
    scanf("%d",&index);
    for(int j = *n;j>=index;j--) arr[j] = arr[j-1];
    arr[index] = val;
    for(int k = 0;k<*(n)+1;k++) printf("%d ",arr[k]);
    *n = *n + 1;
}

void Deletion(int *arr,int *n){
    int del;
    printf("\nEnter the index of the value that you want to delete: ");
    scanf("%d",&del);
    for(int i = del;i<*n;i++) arr[i] = arr[i+1];
    *n = *n - 1;
    for(int k = 0;k<*n;k++) printf("%d ",arr[k]);
}

int BinarySearch(int *arr,int n){
    int target,start = 0,end = n-1,mid;
    printf("\nEnter the value that you want to search: ");
    scanf("%d",&target);
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid] == target) return mid;
        else{
            if(arr[mid] > target) end = mid-1;
            else start = mid+1;
        }
    }
    return -1;
}

int main(void){
    int arr[100],val,index,n,flag = 1,a;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        arr[i] = i+1;
        printf("%d ",arr[i]);
    }
    while(flag){
        printf("\n---------------------------------------------------");
        printf("\nMenu");
        printf("\n---------------------------------------------------");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Search an element");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a == 1)  Insertion(arr,&n);
        else{
            if(a == 2) Deletion(arr,&n);
            else{
                if(a == 3) printf("\nElement found at index: %d",BinarySearch(arr,n));
                else flag = 0;
            }
        }
    }
    return 0;
}