#include<stdio.h>
void cyclesort(int array[] , int array_length);
void swap(int array[] , int a , int b);
void main(void){
    int a[] = {4,5,3,2,1};
    int l=(sizeof(a)/sizeof(int));
    cyclesort(a,l);
    for(int i=0;i<l;i++){
        printf("%d ",a[i]);
    }
}
void cyclesort(int array[] , int array_length){
    int i=0;
    while(i<array_length){
        int correct=array[i]-1;
        if(array[i] != array[correct]) swap(array,i,correct);
        else i++;
    }
}
void swap(int array[] , int a , int b){
    int temp = array[a];
    array[a]=array[b];
    array[b]=temp;
}