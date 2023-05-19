#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 9
int minDistance(int distance[V],bool sptSet[V]){
    int min = INT_MAX,min_index;
    for(int i = 0;i<V;i++){
        if (sptSet[i] == false && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}


void printSolution(int distance[V]){
    printf("vertex\t\tdistance from source\n");
    for(int i =0;i<V;i++){
        printf("%d\t\t\t%d\n",i,distance[i]);
    }
    
}


int dijkstra(int graph[V][V],int src){
    int distance[V];
    bool sptSet[V];
    for(int i;i<V;i++){
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
    distance[src] = 0;
    for( int i =0;i<V-1;i++){
        int u = minDistance(distance,sptSet);
        sptSet[u] = true;
        for(int v = 0;v<V;v++){
            if(graph[u][v] && distance[u]!= INT_MAX && !sptSet[v] && distance[v] > distance[u] + graph[u][v]){
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printSolution(distance);
}


int main(){
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
}