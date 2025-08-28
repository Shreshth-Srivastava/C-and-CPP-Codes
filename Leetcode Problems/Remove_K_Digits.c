#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeKdigits(char* num, int k) {
    int stack[1000], top = 0, counter = 0;
    int N = strlen(num);
    if(N == k) return "0";
    char *result = (char *)malloc(sizeof(char)*N+1);
    stack[0] = (int)num[0] - 48;
    for(int i = 1;i < N;i++){
        if((int)num[i] - 48 < stack[top]){
            if(counter<k){
                stack[top] = (int)num[i] - 48;
                counter++;
            }
            else{
                top++;
                stack[top] = (int)num[i] - 48;
            }
        }
        else{
            top++;
            stack[top] = (int)num[i] - 48;
        }
    }
    int j;
    if(counter < k){
        // for(int m = 0;counter<k;m++){
        //     stack[m] = 0;
        //     counter++;
        // }
        // top = top - counter;
        for(int m = top;counter<k && m>0;m--){
            if(stack[m] > stack[m-1]){
                stack[m] = 0;
                counter++;
                top--;
            }
        }
        while(counter<k){
            if(stack[top] == 0) top--;
            stack[top] = 0;
            counter++;
            top--;
        }
    }
    if(stack[0] == 0){
        int l = 0;
        while(stack[l] == 0 && l < N-k-1) l++;
        for(j = 0;l <= N-k-1;j++){
            result[j] = (char)(stack[l]+48);
            l++;
        }
        result[j] = '\0';
        // if(N <= k){
        //     result[0] = (char)(0+48);
        //     result[1] = '\0';
        // }
        // else{
        //     if(N-k-1 == 0){
        //         result[0] ='0';
        //         result[1] = '\0';
        //     }
        //     else{
        //         // Remove leading zeros
        //         int l = 0;
        //         while(stack[l] == 0 && l < N-k-1) l++;

        //         for(j = 0;l <= N-k-1;j++){
        //             result[j] = (char)(stack[l]+48);
        //             l++;
        //         }
        //         result[j] = '\0';
        //     }
        // }
    }
    else{
        if(N <= k){
            result[0] ='0';
            result[1] = '\0';
        }
        else{
            for(j = 0;j<N-k;j++){
                result[j] = (char)(stack[j]+48);
            }
            result[N-k] = '\0';
        }
    }
    return result;
}

int main(void){
    // char a = '9';
    // printf("%d",(int)a - 48);
    // char *a = "123";
    // printf("%d",strlen(a));
    // char a = (char)(1 + 48);
    // printf("%c",a);
    char *a = removeKdigits("10001",4);
    for(int i=0;i<strlen(a);i++) printf("%c",a[i]);
    return 0;
}