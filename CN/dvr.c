#include<stdio.h>
#define MAX_NODES 20

struct RouterNode {
    unsigned int distance[MAX_NODES];
    unsigned int nextHop[MAX_NODES];
};

int main() {
    int costMatrix[MAX_NODES][MAX_NODES], numOfNode, i, j, k, updateCount = 0;
    struct RouterNode routingTable[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numOfNode);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < numOfNode; i++) {
        for (j = 0; j < numOfNode; j++) {
            scanf("%d", &costMatrix[i][j]);
            routingTable[i].distance[j] = costMatrix[i][j];
            routingTable[i].nextHop[j] = j;
        }
    }

    do {
        updateCount = 0;
        for (i = 0; i < numOfNode; i++) {
            for (j = 0; j < numOfNode; j++) {
                for (k = 0; k < numOfNode; k++) {
                    if (routingTable[i].distance[j] > routingTable[i].distance[k] + routingTable[k].distance[j]) {
                        routingTable[i].distance[j] = routingTable[i].distance[k] + routingTable[k].distance[j];
                        routingTable[i].nextHop[j] = k;
                        updateCount++; 
                    }
                }
            }
        }
    } while (updateCount != 0);

    for (i = 0; i < numOfNode; i++) {
        printf("Routing table for Router %d:\n", i + 1);
        for (j = 0; j < numOfNode; j++) {
            printf("To node %d, Next hop: %d, Distance: %d\n", j + 1, routingTable[i].nextHop[j] + 1, routingTable[i].distance[j]);
        }
        printf("\n");
    }

    return 0;
}
