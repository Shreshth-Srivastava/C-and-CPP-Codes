#include<stdio.h>
int romantoint(char *s);
int main(void){
    char a[]="III";
    char *s=a;
    printf("%d",romantoint(s));
    return 0;
}
int romantoint(char *s){
    int ans=0;
    int i=0;
    while(*(s+i)!='\0'){
        printf("%c \n",*(s+i));;
        if(s[i]=='I'){
            if(s[i+1]=='V'){ 
                ans=ans+4;
                }
            else if(s[i+1]=='X') {
                ans=ans+9;
                }
            else if(s[i+1]=='C') ans=ans+99;
            else if(s[i+1]=='L') ans=ans+49;
            else ans++;
        }
        if(s[i]=='X'){
            if(s[i+1]=='L'){
                ans=ans+40;
            }
            else if(s[i+1]=='C'){
                ans=ans+90;
            }
            else if(s[i-1]=='I') ans=ans;
            else ans=ans+10;
        }
        if(s[i]=='C'){
            if(s[i+1]=='D'){
                ans=ans+400;
            }
            else if(s[i+1]=='M'){
                ans=ans+900;
            }
            else if(s[i-1]=='I') ans=ans;
            else if(s[i-1]=='X') ans=ans;
            else ans=ans+100;
        }
        if(s[i]=='V' && s[i-1]!='I') ans=ans+5;
        else ans=ans;
        if(s[i]=='L' && s[i-1]!='I') ans=ans+50;
        else ans=ans;
        if(s[i]=='D' && s[i-1]!='C') ans=ans+500;
        else ans=ans;
        if(s[i]=='M' && s[i-1]!='C') ans=ans+1000;
        else ans=ans;
        i++;
    }
    return ans;
}