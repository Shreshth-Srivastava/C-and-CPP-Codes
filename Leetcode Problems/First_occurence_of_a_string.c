#include<stdio.h>
#include<string.h>

// Modified Solution

int strStr(char* haystack, char* needle) {
    int count = 0;
    for(int i = 0;haystack[i];i++){
        if(haystack[i] == needle[0] && strlen(haystack)-i >= strlen(needle)){
            count++;
            for(int j = 1;needle[j];j++){
                if(haystack[i+j] != needle[j]) break;
                count++;
            }
            if(count == strlen(needle)) return i;
            else count = 0;
        }
    }
    return -1;
}

// My Solution

int strStr(char* haystack, char* needle) {
    int count = 0;
    for(int i = 0;haystack[i];i++){
        if(haystack[i] == needle[0]){
            count++;
            for(int j = 1;needle[j];j++){
                if(haystack[i+j] != needle[j]) break;
                count++;
            }
            if(count == strlen(needle)) return i;
            else count = 0;
        }
    }
    return -1;
}

int main(void){
    char* haystack = "sadbutsad";
    char* needle = "sad";
    printf("\n%d\n",strStr(haystack,needle));
    return 0;
}