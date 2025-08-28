int romanToInt(char *s){
    int ans=0;
    int i=0;
    for(i=0;s[i];i++){
        if(s[i]=='I'){
            if(s[i+1] != '\0'){
                if(s[i+1]=='V'){
                    ans=ans+4;
                    i++;
                    continue;
                }
                else if(s[i+1]=='X'){
                    ans=ans+9;
                    i++;
                    continue;
                }
                else if(s[i+1]=='C'){
                    ans=ans+99;
                    i++;
                    continue;
                }
            }
            ans++;
            }
        if(s[i]=='X'){
            if(s[i+1] != '\0'){
                if(s[i+1]=='L'){
                    ans=ans+40;
                    i++;
                    continue;
                }
                else if(s[i+1]=='C'){
                    ans=ans+90;
                    i++;
                    continue;
                }
            }
            ans=ans+10;
        }
        if(s[i]=='C'){
            if(s[i+1] != '\0'){
                if(s[i+1]=='D'){
                    ans=ans+400;
                    i++;
                    continue;
                }
                else if(s[i+1]=='M'){
                    ans=ans+900;
                    i++;
                    continue;
                }
            }
            ans=ans+100;
        }
        else if(s[i]=='V') ans=ans+5;
        else if(s[i]=='L') ans=ans+50;
        else if(s[i]=='D') ans=ans+500;
        else if(s[i]=='M') ans=ans+1000;
        else ans=ans;
    }
    return ans;
}