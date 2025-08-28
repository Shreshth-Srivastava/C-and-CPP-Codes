#include<stdio.h>
int getarray(void);
void main(void){
    int *n = getarray();
    for(int i=0;n[i];i++){
        printf("\n%d",n[i]);
    }
}
int getarray(void){
    int array[],l;
    printf("\nEnter the number of elements that you want to enter in the array : ");
    scanf("%d",&l);    
    for(int j=0;j<l;j++){
        printf("\nEnter Element : ");
        scanf("%d",&array[j]);
    }
    return array;
}