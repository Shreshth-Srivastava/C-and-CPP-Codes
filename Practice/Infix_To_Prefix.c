#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isOperator(char a){
    if(a == '+' || a == '-' || a == '/' || a == '*') return 1;
    return 0;
}

void Push(struct stack *sp,char a){
    sp->top++;
    sp->arr[(sp->top)] = a;
}

int Precedence(char a){
    if(a == '/' || a == '*') return 1;
    return 0;
}

char Pop(struct stack *sp){
    sp->top--;
    return sp->arr[(sp->top) + 1];
}

void swap(char *str,int a,int b){
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}

void ReverseString(char *str){
    int N = strlen(str);
    for(int i = 0;i<=N/2;i++) swap(str,i,N-1-i);
}

char *InfixToPrefix(char *infix){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = strlen(infix) + 1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *prefix = (char *)malloc(sp->size * sizeof(char));
    int i = 0,j = 0;
    prefix[sp->size] = '\0';
    ReverseString(infix);
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            prefix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(sp->top == -1){
                Push(sp,infix[i]);
                i++;
            }
            else{
                if(Precedence(infix[i]) >= Precedence(sp->arr[(sp->top)])){
                    Push(sp,infix[i]);
                    i++;
                }
                else{
                    prefix[j] = Pop(sp);
                    j++;
                }
            }
        }
    }
    while(sp->top != -1){
        prefix[j] = Pop(sp);
        j++;
    }
    ReverseString(prefix);
    return prefix;
}

int main(void){
    char infix[8] = "a+b/c-d";
    printf("\nPrefix expression is : %s",InfixToPrefix(infix));
    return 0;
}