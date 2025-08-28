#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int *arr;
};

void Enqueue(struct queue* q,int data){
    if(q->rear == 100) printf("\n!!!Queue Overflow!!!");
    else{
        q->arr[q->rear] = data;
        q->rear++;
    }
}

int Dequeue(struct queue *q){
    if(q->rear == 0 || q->front > q->rear){
        printf("\n!!!Queue Underflow!!!");
        return -1;
    }
    else{    
        q->front++;
        return q->arr[(q->front) - 1];
    }
}

void View(struct queue *q){
    printf("\nElements in the queue are as follows:-");
    for(int i = q->front;i<=q->rear;i++) printf("\n%d",q->arr[i]);
}

int isEmpty(struct queue *q){
    if(q->rear == 0 || q->front > q->rear) return 1;
    return 0;
}

int main(void){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->arr = (int *)malloc(sizeof(int) * 100);
    q->front = 0;
    q->rear = 0;
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d",i);
    visited[i] = 1;
    Enqueue(q,i);
    while(!isEmpty(q)){
        node = Dequeue(q);
        for(int j = 0;j < 7;j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d",j);
                visited[j] = 1;
                Enqueue(q,j);
            }
        }
    }
    return 0;
}