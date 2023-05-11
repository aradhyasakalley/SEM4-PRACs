#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n, int holeSize[])
{
    int i, j;
    int allocation[n];

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    j=0;
    for (i = 0; i < n; i++) // n -> number of processes
    {
        int temp = m;
        while(j<m){
            if(blockSize[j] == holeSize[j] && holeSize[j] >= processSize[i]){
                allocation[i] = j;
                holeSize[j] -= processSize[i];
                break;
            }
            temp--;
            j = (j+1)%m;
            if(temp == 0){
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tAllocated Block no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i\t\t", i + 1);
        printf("%i\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nBlock No.\tBlock Size\tHole Size\n");
    for (int i = 0; i < m; i++)
    {
        printf("%i\t\t", i + 1);
        printf("%i\t\t", blockSize[i]);
        if (holeSize[i] != blockSize[i])
            printf("%i", holeSize[i]);
        else
            printf("Unused block");
        // printf("%i", holeSize[i]);
        printf("\n");
    }
}

void main()
{
    int m, n;

    printf("Enter number of blocks in the memory: "); // m = 5
    scanf("%d", &m);
    printf("Enter number of processes in the input queue: "); // n = 4
    scanf("%d", &n);

    int blockSize[m], processSize[n], holeSize[m];
    printf("Enter each block size: "); // {100, 500, 200, 300, 600}
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
        holeSize[i] = blockSize[i];
    }
    printf("Enter each process size: "); // {212, 417, 112, 426}
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    nextFit(blockSize, m, processSize, n, holeSize);
}