/*
#Requirements :-
1. Creating a graph connecting the points
2. The points consists of two values ✅
3. A three-dimensional matrix for storing input values ✅
4. Applying BFS
5. Queue
Note: If runtime error occurs on the portal, DEFINE the values of M and N as 250
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 62500

typedef struct
{
    unsigned int queue[Max][2];
    unsigned int front;
    unsigned int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}
void Enqueue(Queue *q, unsigned int data1, unsigned int data2)
{
    q->queue[(q->rear)][0] = data1;
    q->queue[(q->rear)][1] = data2;
    q->rear++;
}
unsigned int *Dequeue(Queue *q)
{
    unsigned int *temp = (unsigned int *)malloc(sizeof(unsigned int) * 2);
    temp[0] = q->queue[(q->front)][0];
    temp[1] = q->queue[(q->front)][1];
    q->front++;
    return temp;
};

unsigned int isEmpty(Queue *q)
{
    if (q->front > q->rear)
        return 1;
    return 0;
}

// unsigned int BFS(unsigned int *arr, unsigned int M, unsigned int N, Queue *q)
// {

//     // for (int i = 0; i < M; i++)
//     // {
//     //     for (int j = 0; j < N; j++)
//     //     {
//     //         unsigned int a,b;
//     //         a = i + (arr + i*N + j);
//     //         b = j + (arr + i*N + j + 1);
//     //     }
//     // }
// }

int log2_int(int x)
{
    int result = 0;
    while (x >>= 1)
    {
        result++;
    }
    return result;
}

int main(void)
{
    unsigned int M, N, R, D;
    scanf("%u", &M);
    scanf("%u", &N);
    unsigned int arr[M][N][2];
    bool visited[M][N];
    Queue *q = createQueue();
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int row = 0; row < M; row++)
    {
        for (int column = 0; column < N; column++)
        {
            scanf("%u", &arr[row][column][0]);
        }
    }
    for (int row = 0; row < M; row++)
    {
        for (int column = 0; column < N; column++)
        {
            scanf("%u", &arr[row][column][1]);
        }
    }
    int count = 0;
    unsigned int *node;
    Enqueue(q, 0, 0);
    visited[0][0] = true;
    while (!isEmpty(q))
    {
        node = Dequeue(q);
        count++;
        unsigned int curr1 = *((unsigned int *)node);
        unsigned int curr2 = *((unsigned int *)node + 1);
        printf("\nDequeued (%u,%u)", curr1, curr2);
        // printf("%u",curr1);
        // printf("%u",curr2);
        if(arr[curr1][curr2][1] > arr[curr1][curr2][0]){
            for (int j = 1; j <= arr[curr1][curr2][1]; j++)
            {
                if (curr1 + j < M)
                {
                    if (curr1 + j == M - 1 && curr2 == N - 1)
                    {
                        printf("\nResult:%d", log2_int(count) + 1);
                        return 0;
                    }
                    if (visited[curr1 + j][curr2] == false)
                    {
                        Enqueue(q, curr1 + j, curr2);
                        visited[curr1 + j][curr2] = true;
                        printf("\nEnqueued (%u,%u)", curr1 + j, curr2);
                    }
                }
            }
            for (int i = 1; i <= arr[curr1][curr2][0]; i++)
            {
                if (curr2 + i < N)
                {
                    if (curr1 == M - 1 && curr2 + i == N - 1)
                    {
                        printf("\nResult:%d", log2_int(count) + 1);
                        return 0;
                    }
                    if (visited[curr1][curr2 + i] == false)
                    {
                        Enqueue(q, curr1, curr2 + i);
                        visited[curr1][curr2 + i] = true;
                        printf("\nEnqueued (%u,%u)", curr1, curr2 + i);
                    }
                }
            }
        }
        else{
            for (int i = 1; i <= arr[curr1][curr2][0]; i++)
            {
                if (curr2 + i < N)
                {
                    if (curr1 == M - 1 && curr2 + i == N - 1)
                    {
                        printf("\nResult:%d", log2_int(count) + 1);
                        return 0;
                    }
                    if (visited[curr1][curr2 + i] == false)
                    {
                        Enqueue(q, curr1, curr2 + i);
                        visited[curr1][curr2 + i] = true;
                        printf("\nEnqueued (%u,%u)", curr1, curr2 + i);
                    }
                }
            }
            for (int j = 1; j <= arr[curr1][curr2][1]; j++)
            {
                if (curr1 + j < M)
                {
                    if (curr1 + j == M - 1 && curr2 == N - 1)
                    {
                        printf("\nResult:%d", log2_int(count) + 1);
                        return 0;
                    }
                    if (visited[curr1 + j][curr2] == false)
                    {
                        Enqueue(q, curr1 + j, curr2);
                        visited[curr1 + j][curr2] = true;
                        printf("\nEnqueued (%u,%u)", curr1 + j, curr2);
                    }
                }
            }
        }
    }
    // printf("\nInputted Values:-\n");
    // for(int i = 0;i<M;i++){
    //     for(int j = 0;j<N;j++){
    //         printf("(%u,%u)\t",arr[i][j][0],arr[i][j][1]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
