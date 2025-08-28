#include<stdio.h>
#include<stdbool.h>

void RemoveElement(char *colors,int index){
    for(int j = index;colors[j] != '\0';j++) colors[j] = colors[j+1];
} 

/*int RemoveElement(char *colors,int index,int size){
    for(int j = index;j<size-1;j++) colors[j] = colors[j+1];
    size--;
    return size;
}*/

int Sizeofstr(char *colors){
    int size = 0;
    for(size;colors[size]!='\0';size++);
    return size;
}

bool winnerOfGame(char * colors){
    int flag = 1;
    int Alice = 1;
    int Bob = 0;
    int i = 1, k = 1;
    ///int N = Sizeofstr(colors); 
    while(colors[i] != '\0' && colors[k] != '\0'){
        if(flag == 1){
            /*if(N == 3){
                for(i;i<N;i++){
                    if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A') return true;
                    else return false;
                }
            }*/
            /*else{*/
                for(i;colors[i] != '\0';i++){
                    if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A'){
                        RemoveElement(colors,i);
                        if(k>1) k--;
                        flag = 0;
                        Alice = 1;
                        break;
                    }
                    else{
                        Alice = 0;
                        continue;
                    }
                }
            /*}*/
            if(Alice == 0) return false;
        }
        else{
            for(k;colors[k] != '\0';k++){
                if(colors[k-1] == 'B' && colors[k] == 'B' && colors[k+1] == 'B'){
                    RemoveElement(colors,k);
                    if(i>1) i--;
                    flag = 1;
                    Bob = 0;
                    break;
                }
                else{
                    Bob = 1;
                    continue;
                }
            }
            if(Bob == 1) return true;
        }
    }
    return false;
}

int main(void){
    char colors[80] = "AAAABBBB";
    bool a;
    a = winnerOfGame(colors);
    printf("\n%d",a);
    return 0;
}