#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2nd Solution

typedef struct
{
    int q1[100];
    int rear;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->rear = 0;
    return obj;
}

void myStackPush(MyStack *obj, int x)
{
    obj->q1[(obj->rear)] = x;
    obj->rear++;
}

int myStackPop(MyStack *obj)
{
    int temp = obj->q1[(obj->rear) - 1];
    obj->rear--;
    return temp;
}

int myStackTop(MyStack *obj)
{
    return obj->q1[(obj->rear - 1)];
}

bool myStackEmpty(MyStack *obj)
{
    if (obj->rear == 0)
        return true;
    return false;
}

void myStackFree(MyStack *obj)
{
    free(obj);
}

//My 1st Solution

typedef struct
{
    int q1[100], q2[100];
    int rear;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->rear = 0;
    return obj;
}

void myStackPush(MyStack *obj, int x)
{
    obj->q1[(obj->rear)] = x;
    obj->rear++;
}

int myStackPop(MyStack *obj)
{
    for (int i = (obj->rear) - 1; i >= 0; i--)
    {
        obj->q2[(obj->rear) - 1 - i] = obj->q1[i];
    }
    obj->rear--;
    return obj->q2[0];
}

int myStackTop(MyStack *obj)
{
    return obj->q1[(obj->rear - 1)];
}

bool myStackEmpty(MyStack *obj)
{
    if (obj->rear == 0)
        return true;
    return false;
}

void myStackFree(MyStack *obj)
{
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/