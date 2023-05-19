
#include<stdio.h>
#define MAX_NODES 20

struct RouterNodes {
    unsigned int distance[MAX_NODES];
    unsigned int nextHop[MAX_NODES];
};

int main(){
    int costMatrix[MAX_NODES][MAX_NODES],i,j,k,n,updateCount = 0;
    struct RouterNodes routingTable[MAX_NODES];
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&costMatrix[i][j]);
            routingTable[i].distance[j] = costMatrix[i][j];
            routingTable[i].nextHop[j] = j;
        }
    }

    do{
        updateCount = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(routingTable[i].distance[j] > routingTable[i].distance[k] + routingTable[k].distance[j]){
                        routingTable[i].distance[j] =  routingTable[i].distance[k] + routingTable[k].distance[j];
                        routingTable[i].nextHop[j] = j;
                        updateCount++;
                    }
                }
            }
        }
    }while(updateCount!=0);
    
    for(i=0;i<n;i++){
            printf("for router %d\n",i+1);
            for(j=0;j<n;j++){
                printf("to node : %d, via : %d and distance : %d\n",j+1,routingTable[i].nextHop[j]+1,routingTable[i].distance[j]);
            }
    }
    return 0;
}