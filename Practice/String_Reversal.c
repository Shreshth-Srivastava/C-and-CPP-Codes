#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *str,int a,int b){
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}

char *ReverseString(char *str){
    int size = strlen(str);
    printf("\nsize = %d",size);
    for(int i=0;i<size/2;i++) swap(str,i,size-1-i);
    return str;
}

int main(void){
    char str[5] = "ABCD";
    printf("\n%s",ReverseString(str));
    return 0;
}