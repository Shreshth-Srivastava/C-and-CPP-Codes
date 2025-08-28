#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int *arr;
};

void Push(struct stack *s,int data){
    s->arr[s->top] = data;
    s->top++;
}

int Pop(struct stack *s){
    s->top--;
    return s->arr[(s->top)];
}

int isEmpty(struct stack *s){
    if(s->top == 0) return 1;
    return 0;
}

int main(void){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = (int *)malloc(sizeof(int)*50);
    s->top = 0;
    int start,node;
    int visited[6] = {0,0,0,0,0,0};
    int adj[6][6] = {
        {0,1,0,0,0,0},
        {1,0,1,1,0,0},
        {0,1,0,0,1,0},
        {0,1,0,0,1,1},
        {0,0,1,1,0,0},
        {0,0,0,1,0,0}
    };
    start = 3;
    Push(s,start);
    while(!isEmpty(s)){
        node = Pop(s);
        if(visited[node] == 0){
            printf("%d",node);
            visited[node] = 1;
            for(int j = 5;j>=0;j--){
                if(adj[node][j] == 1 && visited[j] == 0) Push(s,j);
            }   
        }   
    }
    return 0;
}