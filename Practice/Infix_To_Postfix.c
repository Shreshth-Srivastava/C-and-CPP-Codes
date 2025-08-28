#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/') return 1;
    return 0;
}

void Push(struct stack *sp,char a){
    sp->top++;
    sp->arr[(sp->top)] = a;
}

char Pop(struct stack *sp){
    sp->top--;
    return sp->arr[((sp->top) + 1)];
}

int Precedence(char a){
    if(a == '/' || a == '*') return 1;
    return 0;
}

char *InfixToPostfix(char *infix){
    int size = strlen(infix)+1;
    char *postfix = (char *)malloc(size * sizeof(char));
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = size;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0,j = 0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(sp->top == -1){
                Push(sp,infix[i]);
                i++;
            }
            else{
                if(Precedence(infix[i]) > Precedence(sp->arr[(sp->top)])){
                    Push(sp,infix[i]);
                    i++;
                }
                else{
                    postfix[j] = Pop(sp);
                    j++;
                }
            }
        }
    }
    while(sp->top != -1){
        postfix[j] = Pop(sp);
        j++;
    }
    postfix[size] = '\0';
    return postfix;
}

int main(void){
    char *infix = "a+b/t-c";
    printf("\nPostfix expression is : %s",InfixToPostfix(infix));
    return 0;
}