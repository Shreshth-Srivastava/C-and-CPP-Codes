#include<stdio.h>

void swap(unsigned short int *a, unsigned short int *b){
    unsigned short int temp = *a;
    *a = *b;
    *b = temp;
}

void ReverseArray(unsigned short int *arr, int i){
    for(unsigned short int j=0;j<i/2;j++){
        swap(&arr[j],&arr[i-1-j]);
    }
}

int largestInteger(int num){
    unsigned short int arr[10];
    unsigned short int i=0;
    while(num > 0){
        arr[i] = num%10;
        num = num/10;
        i++;
    }
    ReverseArray(arr,i);
    for(unsigned short int j=0;j<i;j++){
        if(!(arr[j]&1)){
            for(unsigned short int k=j+1;k<i;k++){
                if(!(arr[k]&1) && arr[k]>arr[j]) swap(&arr[j],&arr[k]);
            }
        }
        else{
            for(unsigned short int k=j+1;k<i;k++){
                if((arr[k]&1) && arr[k]>arr[j]) swap(&arr[j],&arr[k]);
            }
        }
    }
    num = arr[0];
    for(unsigned short int l=1;l<i;l++){
        num = num*10 + arr[l];
    }
    return num;
}

int main(void){
    printf("\n%d",largestInteger(1234));
    return 0;
}