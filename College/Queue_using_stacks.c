#include<stdio.h>
#include<stdlib.h>

void Push(int *stack,int *top,int data){
    if(*top == 99) printf("\n!!!Queue Overflow!!!");
    else{
        *top = *top + 1;
        stack[(*top)] = data;
    }
}

void Pop(int *stack1,int *stack2,int *top1,int *top2){
    if(*top1 == -1) printf("\n!!!Queue Underflow!!!");
    else{
        while(*top1 > -1){
            Push(stack2,top2,stack1[(*top1)]);
            *top1 = *top1 - 1; 
        }
        printf("\nPopped element: %d",stack2[(*top2)]);
        *top2 = *top2 - 1;
        while(*top2 > -1){
            Push(stack1,top1,stack2[(*top2)]);
            *top2 = *top2 - 1;
        }
    }
}

void View(int *stack,int top){
    if(top == -1) printf("\nQueue is empty");
    else for(int i = 0;i<=top;i++) printf("\n%d",stack[i]);
}

int main(void){
    int *stack1 = (int *)malloc(sizeof(int)*100);
    int *stack2 = (int *)malloc(sizeof(int)*100);
    int queue[100],a,b,top1 = -1,top2 = -1;
    while(1){
        printf("\n-----------------|");
        printf("\n\tMenu");
        printf("\n-----------------|");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. View");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a == 4) break;
        else{
            if(a == 1){
                printf("\nEnter the element: ");
                scanf("%d",&b);
                Push(stack1,&top1,b);
            }
            else{
                if(a == 2){
                    Pop(stack1,stack2,&top1,&top2);
                }
                else{
                    View(stack1,top1);
                }
            }
        }
    }
    return 0;
}