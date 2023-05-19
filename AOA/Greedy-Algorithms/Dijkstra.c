#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 9

int minDistance(int dist[V],bool sptSet[V]){
    int min = INT_MAX,min_index;
    for(int i =0;i<V;i++){
        if(sptSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i; 
        }
    }
    return min_index;
}

void printSolution(int dist[V]){
    printf("Vertex\t\tDistace from the source\n");
    for(int i =0;i<V;i++){
        printf("%d\t\t\t\t%d\n",i,dist[i]);
    }
}
int dijkstra(int graph[V][V],int src){
    int dist[V];
    bool sptSet[V];
    for(int i =0;i<V;i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for(int i =0;i<V-1;i++){
        int u = minDistance(dist,sptSet);
        sptSet[u] = true;
        for(int v =0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[v] > dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main () {
    
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);
    return 0;

    
}