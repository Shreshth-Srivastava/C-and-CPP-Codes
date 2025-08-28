/*
Given:-
1. string 's' containing only "(,),{,},[,]"
2. 1 <= s.length <= 10^4

Requirements:-
1. Stack
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Better Solution {Better Space Complexity}

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if (top == -1) {
                return false;
            }
            if ((s[i] == ')' && stack[top] == '(') || (s[i] == '}' && stack[top] == '{') || (s[i] == ']' && stack[top] == '[')){
                top--;
            } 
            else {
                return false;
            }
        }
    }
    return top == -1;
}

// My Solution

typedef struct{
    char stk[3500]; //Size of 3500 for string of length 10,000
    int top;
} Stack;

void push(Stack* stack,char data){
    stack->stk[(stack->top)] = data;
    stack->top++;
}

void pop(Stack* stack){
    stack->top--;
}

int isEmpty(Stack* stack){
    if(stack->top == 0) return 1;
    return 0;
}

bool isValid(char* s) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    push(stack,s[0]);
    for(int i = 1;s[i];i++){
        if(s[i] == '(' | s[i] == '{' | s[i] == '['){
            push(stack,s[i]);
        }
        else{
            if(!isEmpty(stack)){
                if((s[i] == '}' && stack->stk[(stack->top) - 1] == '{') |(s[i] == ')' && stack->stk[(stack->top) - 1] == '(') |(s[i] == ']' && stack->stk[(stack->top) - 1] == '[')) pop(stack);
                else return false;
            }
            else return false;
        };
    }
    if(isEmpty(stack)) return true;
    return false;
}

int main(void){
    char *s = "()";
    printf("\n%d",isValid(s));
    return 0;
}