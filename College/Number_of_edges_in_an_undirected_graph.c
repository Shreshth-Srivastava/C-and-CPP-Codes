#include<stdio.h>

int NumberOfEdges(int *adj,int *visited,int numnodes){
    int count = 0,i,j;
    for(i = 0;i < numnodes;i++){
        visited[i] = 1;
        for (j = 0; j < numnodes; j++)
        {
            if(*(adj+i*numnodes+j) == 1 && visited[j] == 0) count++;
        }
    }
    return count;
}

int main(void){
    int visited[5] = {0,0,0,0,0};
    int adj[5][5] = {
        {0,1,1,1,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {1,0,1,0,0},
        {0,0,1,0,0}
    };
    printf("\n%d",NumberOfEdges((int *)adj,visited,5));
    return 0;
}