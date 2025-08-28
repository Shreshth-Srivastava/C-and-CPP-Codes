#include<stdio.h>
#include<stdbool.h>

bool winnerOfGame(char * colors){
    int i = 1;
    int count_alice = 0;
    int count_bob = 0;
    while(colors[i] != '\0'){
        if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A'){
            count_alice++;
            i++;
            }
        else{
            if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B'){
                count_bob++;
                i++;
            }
            else i++;
        }
    }
    if(count_alice > count_bob) return true;
    else return false;
    return false;
}

int main(void){
    char colors[80] = "AAAB";
    bool a;
    a = winnerOfGame(colors);
    printf("\n%d",a);
    return 0;
}