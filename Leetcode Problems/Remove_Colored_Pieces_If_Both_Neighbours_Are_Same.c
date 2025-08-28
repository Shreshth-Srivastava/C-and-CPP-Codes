#include<stdio.h>
#include<stdbool.h>

int RemoveElement(char *colors,int index,int size){
    for(int j = index;j<size-1;j++) colors[j] = colors[j+1];
    size--;
    return size;
}  

int Sizeofstr(char *colors){
    int size = 0;
    for(size;colors[size]!='\0';size++);
    return size;
}

bool winnerOfGame(char * colors){
    int flag = 1;
    int Alice = 1;
    int Bob = 0;
    int N = Sizeofstr(colors); 
    while(N>2){
        if(flag == 1){
            if(N == 3){
                for(int i=1;i<N;i++){
                    if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A') return true;
                    else return false;
                }
            }
            else{
                for(int i=1;i<N-1;i++){
                    if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A'){
                        N = RemoveElement(colors,i,N);
                        flag = 0;
                        Alice = 1;
                        break;
                    }
                    else{
                        Alice = 0;
                        continue;
                    }
                }
            }
            if(Alice == 0) return false;
        }
        else{
            for(int k=1;k<N-1;k++){
                if(colors[k-1] == 'B' && colors[k] == 'B' && colors[k+1] == 'B'){
                    N = RemoveElement(colors,k,N);
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
    char colors[80] = {"AAA"};
    bool a;
    a = winnerOfGame(colors);
    printf("\n%d",a);
    return 0;
}