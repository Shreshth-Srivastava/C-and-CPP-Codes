#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//My Solution

typedef struct
{
    int stk1[100], stk2[100];
    int top;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    obj->top = 0;
    return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
    obj->stk1[(obj->top)] = x;
    obj->top++;
}

int myQueuePop(MyQueue *obj)
{
    for (int i = 0; i < obj->top; i++)
    {
        obj->stk2[i] = obj->stk1[(obj->top) - 1 - i];
        obj->stk1[(obj->top) - 1 - i] = 0;
    }
    int temp = obj->stk2[(obj->top) - 1];
    for (int i = (obj->top) - 2; i >= 0; i--)
    {
        obj->stk1[(obj->top) - 2 - i] = obj->stk2[i];
        obj -> stk2[i] = 0;
    }
    obj->top--;
    return temp;
}

int myQueuePeek(MyQueue *obj)
{
    return obj->stk1[0];
}

bool myQueueEmpty(MyQueue *obj)
{
    if (obj->top == 0)
        return true;
    return false;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/