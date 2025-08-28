/*
Given:-
1. 1 <= Length of inputted strings <= 10^4
2. No leading 0's except for 0 itself

Approach-1 :-
1. Need to account for carry.
2. Check for multiple cases
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {
    char carry = '0'; int arrSize = 0, strLen = 0;
    int i = strlen(a)-1, j = strlen(b)-1;
    if(i>j){
        arrSize = i+2;
    }
    else{
        arrSize = j+2;
    }
    int arr[arrSize];
    strLen = arrSize;
    char *d = (char *)malloc(sizeof(char) * strLen+1);
    arrSize--;
    while(i >=0 && j >= 0){
        if(a[i] != b[j]){
            if(carry == '0'){
                arr[arrSize] = 1;
                arrSize--;
            }
            else{
                arr[arrSize] = 0;
                carry = '1';
                arrSize--;
            }
            i--;j--;
        }
        else{
            if(a[i] == '1'){
                if(carry == '0'){
                    arr[arrSize] = 0;
                    carry = '1';
                    arrSize--;
                }
                else{
                    arr[arrSize] = 1;
                    carry = '1';
                    arrSize--;
                }
            }
            else{
                if(carry == '0'){
                    arr[arrSize] = 0;
                    arrSize--;
                }
                else{
                    arr[arrSize] = 1;
                    carry = '0';
                    arrSize--;
                }
            }
            i--;j--;
        }
    }
    if(i >= 0){
        while(i>=0){
            if(a[i] != carry){
                arr[arrSize] = 1;
                arrSize--;
                carry = '0';
            }
            else{
                if(a[i] == '1'){
                    arr[arrSize] = 0;
                    arrSize--;
                    carry = '1';
                }
                else{
                    arr[arrSize] = 0;
                    arrSize--;
                    carry = '0';
                }
            }
            i--;
        }
    }
    if(j >= 0){
        while(j>=0){
            if(b[j] != carry){
                arr[arrSize] = 1;
                arrSize--;
                carry = '0';
            }
            else{
                if(b[j] == '1'){
                    arr[arrSize] = 0;
                    arrSize--;
                    carry = '1';
                }
                else{
                    arr[arrSize] = 0;
                    arrSize--;
                    carry = '0';
                }
            }
            j--;
        }
    }
    if(carry == '0') arr[0] = 0;
    else arr[0] = 1;
    if(arr[0] == 1){
        for(int k = 0;k<strLen;k++){
            char var;
            if(arr[k] == 1) var = '1';
            else var ='0';
            d[k] = var;
        }
        d[strLen] = '\0';
    }
    else{
        for(int k = 1;k<strLen;k++){
            char var;
            if(arr[k] == 1) var = '1';
            else var ='0';
            d[k-1] = var;
        }
        d[strLen] = '\0';
        d[strLen-1] = '\0';
    }
    return d;
}

int main(void){
    char *a = "0", *b = "0";
    char *c = addBinary(a,b);
    for(int i = 0;c[i];i++) printf("%c",c[i]);
    return 0;
}