#include <stdio.h>
#include <stdlib.h>
//Assuming that the given graph consists of 6 nodes
int visited[6] = {0, 0, 0, 0, 0, 0};
int adj[6][6] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0}};

void DFS(int node){     ///Node index is given
    printf("%d",node);
    visited[node] = 1;
    for (int j = 0; j < 6; j++)
    {
        if(adj[node][j] == 1 && visited[j] == 0) DFS(j);
    }
    
}

int main(void)
{
    DFS(3);
    return 0;
}