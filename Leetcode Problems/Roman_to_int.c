#include<stdio.h>
int romantoint(char array[],int array_length);
int main(){
    char s[] = "MCMXCIV";
    int size=(sizeof(s)/sizeof(char));
    printf("%d",romantoint(s,(size)));
    return 0;
}
int romantoint(char array[],int array_length){
    int ans=0;
    int i=0;
    do{
        for(i=0;i<array_length;i++){
            if(array[i]=='I'){
                if(array[i+1]=='V'){ 
                    ans=ans+4;
                    i++;
                    }
                else if(array[i+1]=='X') {
                    ans=ans+9;
                    i++;
                  }
                else if(array[i+1]=='C') ans=ans+99;
                else ans++;
            }
            if(array[i]=='X'){
                if(array[i+1]=='L'){
                    ans=ans+40;
                    i++;
                }
                else if(array[i+1]=='C'){
                    ans=ans+90;
                    i++;;
                }
                else if(array[i-1]=='I') ans=ans;
                else ans=ans+10;
            }
            if(array[i]=='C'){
                if(array[i+1]=='D'){
                    ans=ans+400;
                    i++;
                }
                else if(array[i+1]=='M'){
                    ans=ans+900;
                    i++;
                }
                else if(array[i-1]=='I') ans=ans;
                else if(array[i-1]=='X') ans=ans;
                else ans=ans+100;
            }
            if(array[i]=='V' && array[i-1]!='I') ans=ans+5;
            if(array[i]=='L') ans=ans+50;
            if(array[i]=='D') ans=ans+500;
            if(array[i]=='M' && array[i-1]!='C') ans=ans+1000;
        }
    }while(array[i]!='\0');
    return ans;
}