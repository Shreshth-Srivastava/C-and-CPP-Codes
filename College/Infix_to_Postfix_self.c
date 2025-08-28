#include <stdio.h>
#include <stdlib.h>

void Push(char a, char *stack, int *top)
{
    int b = *top;
    b++;
    stack[b] = a;
    *top = *top + 1;
}

char Pop(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("\n!!!Stack Underflow!!!");
        return '\0';
    }
    else
    {
        int b = *top;
        *top = *top - 1;
        return stack[b];
    }
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

char *InfixToPostfix(char *infix, int size)
{
    char *postfix = (char *)malloc(size * sizeof(char));
    postfix[size - 1] = '\0';
    char stack[size];
    int i = 0, j = 0, top = -1;
    // for (i; infix[i] != '\0'; i++)
    while(infix[i] != '\0')
    {
        if (!(isOperator(infix[i])))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(stack[top]) && top >= 0)
            {
                Push(infix[i], stack, &top);
                i++;
            }
            else
            {
                if (top == -1){
                    Push(infix[i], stack, &top);
                    i++;
                }
                else
                {
                    // while (top >= 0) // The while loop may cause glitches !!
                    // {
                    //     char temp = Pop(stack, &top);
                    //     postfix[j] = temp;
                    //     j++;
                    // }
                    
                    // if (top == -1)
                    //     Push(infix[i], stack, &top);

                    postfix[j] = Pop(stack, &top);
                    j++;
                }
            }
        }
    }
    while (top >= 0)
    {
        char temp = Pop(stack, &top);
        postfix[j] = temp;
        j++;
    }
    return postfix;
}

int main(void)
{
    // char infix[8] = "a-b+t/6";
    char infix[8] = "a-b/t/6";
    char *postfix = InfixToPostfix(infix, 8);
    for (int i = 0; postfix[i] != '\0'; i++)
        printf("%c", postfix[i]);
    return 0;
}