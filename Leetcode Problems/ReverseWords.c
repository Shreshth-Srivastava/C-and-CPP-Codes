#include<stdio.h>

void swap(char *s,int a,int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

char * reverseWords(char * s){
    int start=0;
    int end=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] == ' '){
            end = i-1;
            if((end-start)%2 == 0){
                while(start != end){
                    swap(s,start,end);
                    start++;
                    end--;
                }
            }
            else{
                while(start < end){
                    swap(s,start,end);
                    start++;
                    end--;
                }
            }
            start = i+1;
        }
        else{
            if(s[i+1] == '\0'){
                end = i;
                if((end-start)%2 == 0){
                    while(start != end){
                        swap(s,start,end);
                        start++;
                        end--;
                    }
                }
                else{
                    while(start < end){
                        swap(s,start,end);
                        start++;
                        end--;
                    }
                }
                start = i;
            }
            else continue;
        }
    }
    return s;
}

int main(void){
    char s[80] = "God Ding";
    char *a;
    a = reverseWords(s);
    for(int i=0;s[i]!='\0';i++) printf("%c",a[i]);
    return 0;
}