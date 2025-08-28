#include<stdio.h>
#include<stdbool.h>

#define V 9

int minDist(int dist[], bool spMat[]){
    int min = 999, min_index;
    for(int i = 0;i<V;i++){
        if(spMat[i] == false && dist[i]<=min) min = dist[i], min_index = i;
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool spMat[V];
    for(int j = 0;j<V;j++){
        dist[j] = 999; spMat[j] = false;
    }
    dist[src] = 0;
    for(int i = 0;i<V-1;i++){
        int u = minDist(dist,spMat);
        spMat[u] = true;
        for(int v = 0;v<V;v++){
            if(!spMat[v] && graph[u][v] && dist[u] != 999 && (dist[u] + graph[u][v] < dist[v])) dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                    };
    dijkstra(graph, 1);
    return 0;
}