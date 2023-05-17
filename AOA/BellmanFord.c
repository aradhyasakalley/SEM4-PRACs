#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define V 9
#define INF INT_MAX
int graph[V][V];

void bellmanFord(int start){
    int distance[V];
    for(int i =0;i<V;i++){
        distance[i] = INF;
    }
    distance[start] = 0;


    for(int i =1;i<V-1;i++){
        for(int u =0;u<V;u++){
            for(int v = 0;v<V;v++){
                int w = graph[u][v];
                if(w!=0 && distance[u]!=INF && distance[u] + w < distance[v]){
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    //checking or negative weight cycles
    for(int i =1;i<V-1;i++){
        for(int u =0;u<V;u++){
            for(int v = 0;v<V;v++){
                int w = graph[u][v];
                if(w!=0 && distance[u]!=INF && distance[u] + w < distance[v]){
                   printf("Graph has negative weight cycle");
                   return;
                }
            }
        }
    }

    //printing the distances
    printf("The distances of all vertices from %d : \n",start);
 
    for(int i =0;i<V;i++){
        printf("%d: %d\n",i,distance[i]);
    } 



}


int main(){
    int num_edges,u,v,w;
    printf("enter the number of edges : ");
    scanf("%d",&num_edges);
    for(int i =0;i<num_edges;i++){
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    bellmanFord(0);
    return 0;
}