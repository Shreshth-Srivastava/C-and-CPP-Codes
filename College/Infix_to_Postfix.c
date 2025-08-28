#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *sp, char a){
    sp->top++;
    sp->arr[(sp->top)] = a;
}

char pop(struct stack *sp){
    sp->top--;
    return sp->arr[(sp->top)+1];
}

int isEmpty(struct stack * sp){
    if(sp->top == -1) return 1;
    return 0;
}

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    return 0;
}

int Precedence(char a)
{
    if (a == '/' || a == '*')
        return 1;
    return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(sp->top == -1){
                push(sp, infix[i]);
                i++;
            }
            else{
                if (Precedence(infix[i]) > Precedence(sp->arr[sp->top]))
                {
                    push(sp, infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = pop(sp);
                    j++;
                }
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(void)
{
    // char *infix = "a-b+t/6";
    // char *infix = "a-b/t/6";
    char *infix = "a+b/t-c";
    printf("\nPostfix is %s",infixToPostfix(infix));
    return 0;
}