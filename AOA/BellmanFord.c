#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9 // number of vertices
#define INF INT_MAX // infinity value

int graph[V][V];

void BellmanFord(int start) {
    // initialize distances from start vertex to all other vertices as infinity
    int distances[V];
    for (int i = 0; i < V; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;

    // relax edges repeatedly (V - 1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                int w = graph[u][v];
                if (w != 0 && distances[u] != INF && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }
    }

    // check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            int w = graph[u][v];
            if (w != 0 && distances[u] != INF && distances[u] + w < distances[v]) {
                printf("Graph contains a negative-weight cycle\n");
                return;
            }
        }
    }

    // print the shortest distances from the start vertex to all other vertices
    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < V; i++) {
        printf("%d: %d\n", i, distances[i]);
    }
}

int main() {
    // read input
    int num_edges;
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // add both directions for undirected graph
    }

    // run Bellman-Ford from vertex 0
    BellmanFord(0);

    return 0;
}
