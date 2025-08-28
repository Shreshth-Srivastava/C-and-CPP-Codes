#include<stdio.h>

int main(void){
    int a=1, arr[3] = {0,1,2};
    arr[a++] = 3;
    for(int i=0;i<3;i++) printf("\n%d",arr[i]);
    return 0;
}