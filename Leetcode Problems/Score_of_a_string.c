#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int scoreOfString(char* s) {
    int N = strlen(s);
    int arr1[N],arr2[N-1],result = 0;
    for(int i=0;s[i];i++){
        arr1[i] = s[i];
    }
    for(int j=0;j<N-1;j++){
        arr2[j] = abs(arr1[j] - arr1[j+1]); 
    }
    for(int k = 0;k<N-1;k++){
        result += arr2[k];
    }
    return result;
}

int main(void){
    int a = scoreOfString("hello");
    printf("%d",a);
    return 0;
}