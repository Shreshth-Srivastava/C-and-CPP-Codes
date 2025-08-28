#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int longestCommonSubsequence(char* text1, char* text2) {
//     int n1 = strlen(text1),n2 = strlen(text2),i = 0,j = 0,count = 0;
//     while(i < n1 && j < n2){
//         if(text1[i] == text2[j]){
//             count++;
//             i++;
//             j++;
//         }
//         else{
//             if(n1 - i > n2 - j) i++;
//             else j++;
//         }
//     }
//     return count;
// }

int longestCommonSubsequence(char* text1, char* text2) {
    int n1 = strlen(text1),n2 = strlen(text2),i = 0,j = 0,count = 0,ptr = -1;
    for(int i = 0;i < n1;i++){
        for(int j = ptr+1;j < n2;j++){
            if(text1[i] == text2[j]){
                count++;
                ptr = j;
                break;
            }
        }
    }
    return count;
}

int main(void){
    char *a = "bsbininm", *b = "jmjkbkjkv";
    printf("\nAnswer: %d",longestCommonSubsequence(a,b));
    return 0;
}