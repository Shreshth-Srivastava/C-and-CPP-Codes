#include<stdio.h>
#include<stdlib.h>

//My Solution equivalent to the better solution

char* Result(int count,char** strs){
    char *str = (char *)malloc(sizeof(char)*(count+1));
    for(int i = 0;i<count;i++){
        str[i] = *((char *)strs + i);
    }
    str[count] = '\0';
    return str;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int count = 0,k = 0;
    for(int j = k;*((char *)strs + j);j++){
        for(int i = 1;i<strsSize;i++){
            if(*((char *)strs + i*200 + j) != *((char *)strs + (i-1)*200 + j)){
                return Result(count,strs);
            }
        }
        count++;
        k++;
    }
    return Result(count,strs);
}

int main(void){
    char strs[200][200] = {"dog","racecar","car"};
    int strsSize = 3;
    char *str = longestCommonPrefix((char **)strs,strsSize);
    printf("\nResult: %s\n",str);
    return 0;
}

//For Leetcode

char* Result(int count,char** strs){
    char *str = (char *)malloc(sizeof(char)*(count+1));
    for(int i = 0;i<count;i++){
        str[i] = strs[0][i];
    }
    str[count] = '\0';
    return str;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int count = 0,k = 0;
    for(int j = k;strs[0][j];j++){
        for(int i = 1;i<strsSize;i++){
            if(strs[i][j] != strs[i-1][j]){
                return Result(count,strs);
            }
        }
        count++;
        k++;
    }
    return Result(count,strs);
}

//Better Solution

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0)
        return "";
    int prefixLen = strlen(strs[0]);
    for(int i=0;i<prefixLen;i++){
        for(int j=1;j<strsSize;j++){
            if(i == strlen(strs[j]) || strs[0][i] != strs[j][i]){
                char* res = (char*)malloc(sizeof(char) * (i+1));
                strncpy(res, strs[0], i);
                res[i] = '\0';
                return res;
            }
        }
    }
    return strs[0];
}