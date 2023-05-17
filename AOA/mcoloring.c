#include<stdio.h>
#include<stdbool.h>
#define V 4

bool isSafe(bool graph[V][V], int color[V]) {
    int i,j;
    for(i = 0; i < V; i++) {
        for(j = i + 1; j < V; j++) {
            if(graph[i][j] && color[j] == color[i]) {
                return false;
            }
        }
    }
    return true;
}

void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors\n");
    for(int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

bool graphColoring(bool graph[V][V], int m, int i, int color[V]) {
    if(i == V) {
        if(isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }

    for(int j = 1; j <= m; j++) {
        color[i] = j;

        if(graphColoring(graph, m, i + 1, color)) {
            return true;
        }

        color[i] = 0;
    }

    return false;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;
    int color[V];

    for(int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if(!graphColoring(graph, m, 0, color)) {
        printf("Solution does not exist\n");
    }

    return 0;
}

