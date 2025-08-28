#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//Better Solution

bool buddyStrings(char* s, char* goal) {
    int count[26] = {0};
    if(strlen(s) != strlen(goal)) return false;
    else{
        for(int i = 0;i < strlen(goal);i++){
            if(!strcmp(s,goal)){
                for(int i = 0;i < strlen(s);i++){
                    count[s[i] - 'a']++;
                    if(count[s[i] - 'a'] > 1) return true;
                }
                return false;
            }
        }
        int index1 = -1,index2 = -1;
        for(int i = 0;i < strlen(s);i++){
            if(s[i] != goal[i]){
                if(index1 == -1) index1 = i;
                else{
                    if(index2 == -1) index2 = i;
                    else return false;
                }
            }
        }
        if(index2 == -1) return false;
        return (s[index1] == goal[index2] && s[index2] == goal[index1]);
    }
}

//My Solution

void swap(char *s,int i,int index){
    char temp = s[i];
    s[i] = s[index];
    s[index] = temp;
}

bool buddyStrings(char* s, char* goal) {
    int count[26] = {0};
    if(strlen(s) != strlen(goal)) return false;
    else{
        for(int i = 0;i < strlen(goal);i++){
            if(!strcmp(s,goal)){
                for(int i = 0;i < strlen(s);i++){
                    count[s[i] - 'a']++;
                    if(count[s[i] - 'a'] > 1) return true;
                }
                return false;
            }
            else{
                int n = strlen(s),i = 0,j = n-1;
                while(i<n && s[i] == goal[i]){
                    i++;
                }
                while(j>=0 && s[j] == goal[j]){
                    j--;
                }
                char s1[strlen(s)+1];
                for(int k = 0;k < strlen(s)+1;k++) s1[k] = s[k];
                if(i<j){
                    swap(s1,i,j);
                }
                return !strcmp(s1,goal);
            }
        }
    }
    return false;
}

int main(void){
    char *s = "ab", *goal = "ba";
    printf("\nAnswer: %d",buddyStrings(s,goal));
    return 0;
    
}